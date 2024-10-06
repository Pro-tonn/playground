#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// User structure
struct User {
    int id;
    string name;
    vector<int> friends;
    vector<string> posts;
};

// Social Media class
class SocialMedia {
    map<int, User> users;
    int nextUserId = 0;

public:
    // Add a new user
    void addUser(const string& name) {
        users[nextUserId] = {nextUserId, name, {}, {}};
        cout << "Added user: " << name << " with ID: " << nextUserId << "\n";
        nextUserId++;
    }

    // Make two users friends
    void addFriendship(int userId1, int userId2) {
        if (users.find(userId1) != users.end() && users.find(userId2) != users.end()) {
            users[userId1].friends.push_back(userId2);
            users[userId2].friends.push_back(userId1);
            cout << users[userId1].name << " and " << users[userId2].name << " are now friends!\n";
        } else {
            cout << "One or both users not found!\n";
        }
    }

    // Post a message with simple templating
    void postMessage(int userId, const string& templateStr) {
        if (users.find(userId) != users.end()) {
            string post = processTemplate(users[userId].name, templateStr);
            users[userId].posts.push_back(post);
            cout << users[userId].name << " posted: " << post << "\n";
        } else {
            cout << "User not found!\n";
        }
    }

    // Process the template and replace placeholders with user-specific info
    string processTemplate(const string& username, const string& templateStr) {
        string result = templateStr;
        string placeholder = "{username}";
        size_t pos = result.find(placeholder);

        // Replace all occurrences of {username} with the actual username
        while (pos != string::npos) {
            result.replace(pos, placeholder.length(), username);
            pos = result.find(placeholder, pos + username.length());
        }

        return result;
    }

    // View a user's timeline (including their friends' posts)
    void viewTimeline(int userId) {
        if (users.find(userId) != users.end()) {
            cout << "Timeline for " << users[userId].name << ":\n";
            // Show the user's own posts
            for (const string& post : users[userId].posts) {
                cout << "- " << post << "\n";
            }
            // Show the friends' posts
            for (int friendId : users[userId].friends) {
                for (const string& post : users[friendId].posts) {
                    cout << "- (Friend " << users[friendId].name << ") " << post << "\n";
                }
            }
        } else {
            cout << "User not found!\n";
        }
    }

    // Breadth-first search to find mutual friends between two users
    void findMutualFriends(int userId1, int userId2) {
        if (users.find(userId1) != users.end() && users.find(userId2) != users.end()) {
            vector<int> mutualFriends;

            // Check friends of userId1
            for (int friendId1 : users[userId1].friends) {
                // Check if this friend is also a friend of userId2
                for (int friendId2 : users[userId2].friends) {
                    if (friendId1 == friendId2) {
                        mutualFriends.push_back(friendId1);
                    }
                }
            }

            if (!mutualFriends.empty()) {
                cout << "Mutual friends between " << users[userId1].name << " and " << users[userId2].name << ": ";
                for (int mutual : mutualFriends) {
                    cout << users[mutual].name << " ";
                }
                cout << "\n";
            } else {
                cout << "No mutual friends found.\n";
            }
        } else {
            cout << "One or both users not found!\n";
        }
    }
};

int main() {
    SocialMedia sm;

    // Adding users
    sm.addUser("Alice");
    sm.addUser("Bob");
    sm.addUser("Charlie");
    sm.addUser("David");

    // Creating friendships
    sm.addFriendship(0, 1);  // Alice and Bob
    sm.addFriendship(1, 2);  // Bob and Charlie
    sm.addFriendship(0, 2);  // Alice and Charlie
    sm.addFriendship(2, 3);  // Charlie and David

    // Posting messages using templates
    sm.postMessage(0, "Hello, I'm {username}, and I love programming!");
    sm.postMessage(1, "Hey! This is {username}, enjoying my coffee!");
    sm.postMessage(2, "{username} just finished a great workout session.");
    sm.postMessage(3, "It's a beautiful day, says {username}!");

    // Viewing a user's timeline
    sm.viewTimeline(0);  // Alice's timeline

    // Finding mutual friends between two users
    sm.findMutualFriends(0, 3);  // Alice and David

    return 0;
}
