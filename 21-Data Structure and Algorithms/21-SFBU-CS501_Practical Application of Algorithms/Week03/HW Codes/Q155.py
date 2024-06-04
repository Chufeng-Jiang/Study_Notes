# Define the MinStack
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    def pop(self) -> None:
        if self.stack.pop() == self.min_stack[-1]:
            self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


""" test"""


def test_min_stack(operations, values):
    min_stack = MinStack()
    results = []

    for op, val in zip(operations, values):
        if op == "MinStack":
            results.append(None)
        elif op == "push":
            min_stack.push(val[0])
            results.append(None)
        elif op == "pop":
            min_stack.pop()
            results.append(None)
        elif op == "top":
            results.append(min_stack.top())
        elif op == "getMin":
            results.append(min_stack.getMin())

    return results


operations = ["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
values = [[], [-2], [0], [-3], [], [], [], []]
output = test_min_stack(operations, values)
print(output)
