class BrowserHistory:
    def __init__(self, homepage: str):
        self.a = [homepage]
        self.i = 0

    def visit(self, url: str) -> None:
        del self.a[self.i + 1:]
        self.a.append(url)
        self.i += 1

    def back(self, steps: int) -> str:
        self.i = max(0, self.i - steps)
        return self.a[self.i]

    def forward(self, steps: int) -> str:
        self.i = min(self.i + steps, len(self.a) - 1)
        return self.a[self.i]

""" test """
def test_browser_history(operations, values):
    browser_history = None
    results = []

    for op, val in zip(operations, values):
        if op == "BrowserHistory":
            browser_history = BrowserHistory(val[0])
            results.append(None)
        elif op == "visit":
            browser_history.visit(val[0])
            results.append(None)
        elif op == "back":
            results.append(browser_history.back(val[0]))
        elif op == "forward":
            results.append(browser_history.forward(val[0]))

    return results

""" input """
operations = ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
values = [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]

output = test_browser_history(operations, values)
print(output)
