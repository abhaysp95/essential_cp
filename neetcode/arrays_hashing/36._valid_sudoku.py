import typing as ty

class Solution:
    def isValidSudoku(self, board: ty.List[ty.List[str]]) -> bool:
        def validate_row(point: int) -> bool:
            freq: list[int] = [0] * 10
            for x in range(9):
                if board[point][x] == ".":
                    continue
                if freq[int(board[point][x])] != 0:
                    return False
                freq[int(board[point][x])] = 1
            return True
        def validate_col(point: int) -> bool:
            freq: list[int] = [0] * 10
            for x in range(9):
                if board[x][point] == ".":
                    continue
                if freq[int(board[x][point])] != 0:
                    return False
                freq[int(board[x][point])] = 1
                print(freq)
            return True
        # validate 3x3 matrix
        def validate_matrix(point: tuple[int, int]) -> bool:
            freq: list[int] = [0] * 10
            for i in range(3):
                for j in range(3):
                    if board[point[0]+i][point[1]+j] == ".":
                        continue
                    if freq[int(board[point[0]+i][point[1]+j])] != 0:
                            return False
                    freq[int(board[point[0]+i][point[1]+j])] = 1
            return True
        
        # validate row & col
        for i in range(9):
            if not (validate_row(i) and validate_col(i)) :
                return False
        # validate matrix
        for i in range(9):
            for j in range(9):
                if i % 3 == 0 and j % 3 == 0:
                    if not validate_matrix((i, j)):
                        return False
        return True

T = int(input())
while T:
    inp: str = input()[1:-1]
    mat: list[list[str]] = []
    splits: list[str] = inp.split("],")
    for i, x in enumerate(splits):
        mat.append([])
        if i == len(splits) - 1:
            for n in x[1:-1].split(","):
                mat[i].append(n[1])
        else:
            for n in x[1:].split(","):
                mat[i].append(n[1])
    print(Solution().isValidSudoku(mat))
    T -= 1
