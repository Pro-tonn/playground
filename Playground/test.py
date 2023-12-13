class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        print(f"{self.name} makes a noise.")

    def eat(self):
        print(f"{self.name} is eating.")

    def selftype(self):
        print(f"Type of self is {self.__class__.__name__}")


class Dog(Animal):
    def __init__(self, name):
        super().__init__(name)

    def speak(self):
        print(f"{self.name} barks.")

obj = Animal("Dog")
dog = Dog("Dog")
dog.selftype()
obj.selftype()
