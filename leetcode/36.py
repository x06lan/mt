class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(3):
            d=""
            for j in range(3):
                d+=board[i*3][j*3]+board[i*3+1][j*3+1]+board[i*3+2][j*3+2]
            for k in range(1,10):
                if d.count(str(k))>1: 
                    return False
        for i in range(1,10):
            for j in range(1,10):
                if board[i].count(str(j)):
                    return False
        for i in range(1,10):
            d=''
            for j in range(1,10):
                d+=board[j][i]
            for k in range(1,10):
                 if board[i].count(str(j)):
                    return False



