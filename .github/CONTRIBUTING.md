# Contributing to DSA-Mastery

## Ways to Contribute
1. Add new algorithm implementations
2. Add problem solutions
3. Fix bugs or improve existing code
4. Add tests
5. Improve documentation

## Code Standards

### Python
- Python 3.12+
- Type hints required
- Docstrings with time/space complexity
- pytest tests required

### C++
- C++20
- Doxygen comments
- namespace `dsa`
- Test with assertions

## Pull Request Process
1. Fork the repository
2. Create feature branch: `git checkout -b feature/algorithm-name`
3. Write code + tests
4. Run all tests: `pytest tests/`
5. Submit PR with description

## Commit Message Format
```
type(scope): description

feat(graphs): add Tarjan's SCC algorithm
fix(sorting): fix quick sort worst-case handling
docs(trees): add BST deletion explanation
test(dp): add coin change edge cases
```

## Problem Solution Template
```python
"""
Problem Name
============
Difficulty: Easy/Medium/Hard
Time:  O(...)
Space: O(...)
Pattern: ...
LeetCode #...
"""
```
