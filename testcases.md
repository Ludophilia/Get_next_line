# BUFFER_SIZE = -1

- [x] all cases
	-> NULL

# BUFFER_SIZE = 0

- [x] all cases
	-> NULL

# BUFFER_SIZE = 1

- [x] fd < 0
	-> NULL

- [x] empty file
	-> NULL (nothing to read)

- [x] file with 1 newline
	-> "\n" (first call)
	-> NULL (second call)

- [x] file with 3 newlines
	-> "\n" (1 call)
	-> "\n" (2 call)
	-> "\n" (3 call)
	-> NULL (4 call)

- [x] file with one character, no new line
	-> "d" (1 call)
	-> NULL (2 call)

- [x] file with 42 characters, no new line
	-> "01234567890123456789012345678901" (1 call)
	-> NULL (2 call)

- [x] file with 42 characters, with new line
	-> "01234567890123456789012345678901\n" (1 call)
	-> NULL (2 call)

- [x] file with 42 characters, with new line, on 3 lines, no newline at the end
	-> "01234567890123456789012345678901\n" (1 call)
	-> "01234567890123456789012345678901\n" (2 call)
	-> "01234567890123456789012345678901" (3 call)
	-> NULL (4 call)

- [x] file with alternative newlines, no newline at the end
	-> "01234567890123456789012345678901\n" (1 call)
	-> "\n" (2 call)
	-> "01234567890123456789012345678901" (3 call)
	-> NULL (4 call)

- [x] file with alternative newlines, newline at the end
	-> "01234567890123456789012345678901\n" (1 call)
	-> "\n" (2 call)
	-> "01234567890123456789012345678901\n" (3 call)
	-> NULL (4 call)

- [ ] Big text no newline
	-> ...

- [ ] Big text with newline
	-> ...

# BUFFER_SIZE = 69

- [x] fd < 0
	-> NULL

- [x] empty file
	-> NULL (nothing to read)

- [x] file with 1 newline
	-> "\n" (first call)
	-> NULL (second call)

- [x] file with 3 newlines
	-> "\n" (1 call)
	-> "\n" (2 call)
	-> "\n" (3 call)
	-> NULL (4 call)

- [x] file with one character, no new line
	-> "d" (1 call)
	-> NULL (2 call)

- [x] file with 42 characters, no new line
	-> "01234567890123456789012345678901" (1 call)
	-> NULL (2 call)

- [x] file with 42 characters, with new line
	-> "01234567890123456789012345678901\n" (1 call)
	-> NULL (2 call)

- [x] file with 42 characters, with new line, on 3 lines, no newline at the end
	-> "01234567890123456789012345678901\n" (1 call)
	-> "01234567890123456789012345678901\n" (2 call)
	-> "01234567890123456789012345678901" (3 call)
	-> NULL (4 call)

- [x] file with alternative newlines, no newline at the end
	-> "01234567890123456789012345678901\n" (1 call)
	-> "\n" (2 call)
	-> "01234567890123456789012345678901" (3 call)
	-> NULL (4 call)

- [x] file with alternative newlines, newline at the end
	-> "01234567890123456789012345678901\n" (1 call)
	-> "\n" (2 call)
	-> "01234567890123456789012345678901\n" (3 call)
	-> NULL (4 call)

- [ ] Big text no newline
	-> ...

- [ ] Big text with newline
	-> ...

# BUFFER_SIZE = 10000000 (10 millions)

- [x] fd < 0
	-> NULL

- [x] empty file
	-> NULL (nothing to read)

- [x] file with 1 newline
	-> "\n" (first call)
	-> NULL (second call)

- [x] file with 3 newlines
	-> "\n" (1 call)
	-> "\n" (2 call)
	-> "\n" (3 call)
	-> NULL (4 call)

- [x] file with one character, no new line
	-> "d" (1 call)
	-> NULL (2 call)

- [x] file with 42 characters, no new line
	-> "01234567890123456789012345678901" (1 call)
	-> NULL (2 call)

- [x] file with 42 characters, with new line
	-> "01234567890123456789012345678901\n" (1 call)
	-> NULL (2 call)

- [x] file with 42 characters, with new line, on 3 lines, no newline at the end
	-> "01234567890123456789012345678901\n" (1 call)
	-> "01234567890123456789012345678901\n" (2 call)
	-> "01234567890123456789012345678901" (3 call)
	-> NULL (4 call)

- [x] file with alternative newlines, no newline at the end
	-> "01234567890123456789012345678901\n" (1 call)
	-> "\n" (2 call)
	-> "01234567890123456789012345678901" (3 call)
	-> NULL (4 call)

- [x] file with alternative newlines, newline at the end
	-> "01234567890123456789012345678901\n" (1 call)
	-> "\n" (2 call)
	-> "01234567890123456789012345678901\n" (3 call)
	-> NULL (4 call)

- [ ] Big text no newline
	-> ...

- [ ] Big text with newline
	-> ...