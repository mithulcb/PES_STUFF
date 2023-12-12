import pygame
import os
letterX = pygame.image.load(os.path.join('Assets', 'x.png'))
letterO = pygame.image.load(os.path.join('Assets', 'o.png'))
class Game:
    def __init__(self):
        self.gridLines = [((0, 200), (600, 200)),
        ((0, 400), (600, 400)),
        ((200, 0), (200, 600)),
        ((400, 0), (400, 600))]
        self.grid = [[0 for x in range(3)] for y in range(3)]
        self.searchDirs = [(0, -1), (-1, -1), (-1, 0),
        (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]
        self.isGameOver = False

    def draw(self, surface):
        for line in self.gridLines:
            pygame.draw.line(surface, (200, 200, 200), line[0], line[1], 2)
        for y in range(len(self.grid)):
            for x in range(len(self.grid[y])):
                if self.getCell(x, y) == "X":
                    surface.blit(letterX, (x*200, y*200))
                elif self.getCell(x, y) == "O":
                    surface.blit(letterO, (x*200, y*200))

    def getCell(self, x, y):
        return self.grid[y][x]

    def setCell(self, x, y, value):
        self.grid[y][x] = value

    def getMouse(self, x, y, player):
        if self.getCell(x, y) == 0:
            self.setCell(x, y, player)
            self.check(x, y, player)

    def isValid(self, x, y):
        return x >= 0 and x < 3 and y >= 0 and y < 3

    def check(self, x, y, player):
        count = 1
        for index, (dirX, dirY) in enumerate(self.searchDirs):
            if self.isValid(x+dirX, y+dirY) and self.getCell(x+dirX, y+dirY)== player:
                count += 1
                X = x + dirX
                Y = y + dirY
                if self.isValid(X+dirX, Y+dirY) and self.getCell(X+dirX,Y+dirY) == player:
                    count += 1
                    if count == 3:
                        break
                if count < 3:
                    dirNew = 0
                    if index == 0:
                        dirNew = self.searchDirs[4]
                    elif index == 1:
                        dirNew = self.searchDirs[5]
                    elif index == 2:
                        dirNew = self.searchDirs[6]
                    elif index == 3:
                        dirNew = self.searchDirs[7]
                    elif index == 4:
                        dirNew = self.searchDirs[0]
                    elif index == 5:
                        dirNew = self.searchDirs[1]
                    elif index == 6:
                        dirNew = self.searchDirs[2]
                    elif index == 7:
                        dirNew = self.searchDirs[3]
                    if self.isValid(x + dirNew[0], y + dirNew[1]) and self.getCell(x + dirNew[0], y + dirNew[1]) == player:
                        count += 1
                        if count == 3:
                            break
                        else:
                            count = 1
        if count == 3:
            print(player, 'wins!')
            self.isGameOver = True
        else:
            self.isGameOver = self.isFull()
    
    def isFull(self):
        for row in self.grid:
            for value in row:
                if value == 0:
                    return False
        return True

    def clear(self):
        for y in range(len(self.grid)):
            for x in range(len(self.grid[y])):
                self.setCell(x, y, 0)

    def print(self):
        for row in self.grid:
            print(row)
