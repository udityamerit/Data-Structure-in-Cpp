import inspect
from typing import List, Dict, Any, Callable
import time
import json

class ProblemStatement:
    def __init__(self, id: int, title: str, difficulty: str, description: str, 
                 function_template: str, test_cases: List[Dict[str, Any]]):
        self.id = id
        self.title = title
        self.difficulty = difficulty
        self.description = description
        self.function_template = function_template
        self.test_cases = test_cases

class CodeEvaluator:
    def __init__(self):
        self.problems = {}
        self._load_sample_problems()

    def _load_sample_problems(self):
        # Problem 1: Two Sum (Easy)
        two_sum_problem = ProblemStatement(
            id=1,
            title="Two Sum",
            difficulty="Easy",
            description="""
            Given an array of integers nums and an integer target, return indices of the two numbers that add up to target.
            You may assume that each input would have exactly one solution, and you may not use the same element twice.
            """,
            function_template="""def two_sum(nums: List[int], target: int) -> List[int]:
    # Write your solution here
    pass""",
            test_cases=[
                {
                    "input": {"nums": [2, 7, 11, 15], "target": 9},
                    "expected": [0, 1]
                },
                {
                    "input": {"nums": [3, 2, 4], "target": 6},
                    "expected": [1, 2]
                }
            ]
        )
        
        # Problem 2: Valid Palindrome (Easy)
        valid_palindrome = ProblemStatement(
            id=2,
            title="Valid Palindrome",
            difficulty="Easy",
            description="""
            Given a string s, return true if it is a palindrome, or false otherwise.
            A string is a palindrome when it reads the same backward as forward.
            Consider only alphanumeric characters and ignore cases.
            """,
            function_template="""def is_palindrome(s: str) -> bool:
    # Write your solution here
    pass""",
            test_cases=[
                {
                    "input": {"s": "A man, a plan, a canal: Panama"},
                    "expected": True
                },
                {
                    "input": {"s": "race a car"},
                    "expected": False
                },
                {
                    "input": {"s": " "},
                    "expected": True
                }
            ]
        )

        # Problem 3: Maximum Subarray (Medium)
        max_subarray = ProblemStatement(
            id=3,
            title="Maximum Subarray",
            difficulty="Medium",
            description="""
            Given an integer array nums, find the subarray with the largest sum, and return its sum.
            A subarray is a contiguous non-empty sequence of elements within an array.
            """,
            function_template="""def max_subarray(nums: List[int]) -> int:
    # Write your solution here
    pass""",
            test_cases=[
                {
                    "input": {"nums": [-2,1,-3,4,-1,2,1,-5,4]},
                    "expected": 6
                },
                {
                    "input": {"nums": [1]},
                    "expected": 1
                },
                {
                    "input": {"nums": [5,4,-1,7,8]},
                    "expected": 23
                }
            ]
        )

        # Problem 4: Longest Substring Without Repeating Characters (Medium)
        longest_substring = ProblemStatement(
            id=4,
            title="Longest Substring Without Repeating Characters",
            difficulty="Medium",
            description="""
            Given a string s, find the length of the longest substring without repeating characters.
            A substring is a contiguous non-empty sequence of characters within a string.
            """,
            function_template="""def length_of_longest_substring(s: str) -> int:
    # Write your solution here
    pass""",
            test_cases=[
                {
                    "input": {"s": "abcabcbb"},
                    "expected": 3
                },
                {
                    "input": {"s": "bbbbb"},
                    "expected": 1
                },
                {
                    "input": {"s": "pwwkew"},
                    "expected": 3
                }
            ]
        )

        # Add all problems to the problems dictionary
        self.problems[1] = two_sum_problem
        self.problems[2] = valid_palindrome
        self.problems[3] = max_subarray
        self.problems[4] = longest_substring

    def get_problem(self, problem_id: int) -> ProblemStatement:
        return self.problems.get(problem_id)

    def list_problems(self) -> List[Dict[str, Any]]:
        return [
            {
                "id": problem.id,
                "title": problem.title,
                "difficulty": problem.difficulty
            }
            for problem in self.problems.values()
        ]

    def evaluate_submission(self, problem_id: int, submitted_code: str) -> Dict[str, Any]:
        problem = self.get_problem(problem_id)
        if not problem:
            return {"status": "error", "message": "Problem not found"}

        # Create namespace for code execution
        namespace = {}
        try:
            # Execute submitted code in isolated namespace
            exec(submitted_code, namespace)
        except Exception as e:
            return {
                "status": "error",
                "message": f"Code execution failed: {str(e)}",
                "test_results": [],
                "score": 0
            }

        # Get the function from namespace
        func_name = submitted_code.split("def ")[1].split("(")[0]
        solution_func = namespace.get(func_name)

        if not solution_func:
            return {
                "status": "error",
                "message": "Could not find solution function",
                "test_results": [],
                "score": 0
            }

        # Run test cases
        test_results = []
        passed_tests = 0
        total_time = 0

        for i, test_case in enumerate(problem.test_cases):
            start_time = time.time()
            try:
                result = solution_func(**test_case["input"])
                execution_time = (time.time() - start_time) * 1000  # Convert to milliseconds
                total_time += execution_time

                if result == test_case["expected"]:
                    passed_tests += 1
                    status = "passed"
                else:
                    status = "failed"

                test_results.append({
                    "test_number": i + 1,
                    "status": status,
                    "input": test_case["input"],
                    "expected": test_case["expected"],
                    "actual": result,
                    "execution_time": f"{execution_time:.2f}ms"
                })

            except Exception as e:
                test_results.append({
                    "test_number": i + 1,
                    "status": "error",
                    "input": test_case["input"],
                    "error": str(e)
                })

        score = (passed_tests / len(problem.test_cases)) * 100

        return {
            "status": "completed",
            "test_results": test_results,
            "score": score,
            "execution_time": f"{total_time:.2f}ms",
            "passed_tests": passed_tests,
            "total_tests": len(problem.test_cases)
        }

class CodingPlatform:
    def __init__(self):
        self.evaluator = CodeEvaluator()

    def list_all_problems(self):
        problems = self.evaluator.list_problems()
        print("\nAvailable Problems:")
        print("-" * 50)
        for problem in problems:
            print(f"#{problem['id']} - {problem['title']} ({problem['difficulty']})")

    def display_problem(self, problem_id: int):
        problem = self.evaluator.get_problem(problem_id)
        if not problem:
            print("Problem not found")
            return

        print(f"\nProblem #{problem.id}: {problem.title}")
        print(f"Difficulty: {problem.difficulty}")
        print("\nDescription:")
        print(problem.description)
        print("\nFunction Template:")
        print(problem.function_template)

    def submit_solution(self, problem_id: int, solution_code: str):
        result = self.evaluator.evaluate_submission(problem_id, solution_code)
        self._display_results(result)

    def _display_results(self, result: Dict[str, Any]):
        if result["status"] == "error":
            print(f"\nError: {result['message']}")
            return

        print("\nEvaluation Results:")
        print(f"Score: {result['score']}%")
        print(f"Passed Tests: {result['passed_tests']}/{result['total_tests']}")
        print(f"Total Execution Time: {result['execution_time']}")

        print("\nDetailed Test Results:")
        for test_result in result["test_results"]:
            print(f"\nTest #{test_result['test_number']}")
            print(f"Status: {test_result['status']}")
            if test_result['status'] != "error":
                print(f"Input: {test_result['input']}")
                print(f"Expected: {test_result['expected']}")
                print(f"Actual: {test_result['actual']}")
                print(f"Execution Time: {test_result['execution_time']}")
            else:
                print(f"Error: {test_result['error']}")

# Example usage
def main():
    platform = CodingPlatform()
    
    # List all available problems
    platform.list_all_problems()
    
    # Example: Let's solve the Valid Palindrome problem
    print("\nTesting Valid Palindrome Problem:")
    platform.display_problem(2)
    
    solution_code = """
def is_palindrome(s: str) -> bool:
    # Convert to lowercase and keep only alphanumeric characters
    cleaned = ''.join(c.lower() for c in s if c.isalnum())
    # Check if the string equals its reverse
    return cleaned == cleaned[::-1]
"""
    
    print("\nSubmitting solution...")
    platform.submit_solution(2, solution_code)

if __name__ == "__main__":
    main()