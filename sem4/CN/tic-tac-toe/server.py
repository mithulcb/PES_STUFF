import socket
import threading
import pygame
import argparse
from game import Game
parser = argparse.ArgumentParser(description='A simple game server')
parser.add_argument('port', nargs='?', help='Port number of host to listenon', type=int, default=65432)
args = parser.parse_args()
HOST = '0.0.0.0'
PORT = args.port
surface = pygame.display.set_mode((600, 600))
pygame.display.set_caption('Tic Tac Toe - Server')
connection_established = False
conn, addr = None, None
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind((HOST, PORT))
sock.listen(1)
def newConnection():
    global connection_established, conn, addr, turn
    conn, addr = sock.accept()
    connection_established = True
    while True:
        data = conn.recv(1024).decode()
        data = data.split('-')
        x, y = int(data[0]), int(data[1])
        if data[2] == 'yourTurn':
            turn = True
        if data[3] == 'False':
            game.isGameOver = True
        if game.getCell(x, y) == 0:
            game.setCell(x, y, 'O')
thread = threading.Thread(target=newConnection)
thread.daemon = True
thread.start()

game = Game()
running = True
player = 'X'
turn = True
playing = 'True'
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.MOUSEBUTTONDOWN and not game.isGameOver:
            if pygame.mouse.get_pressed()[0]:
                if turn and not game.isGameOver:
                    pos = pygame.mouse.get_pos()
                    cellX, cellY = pos[0] // 200, pos[1] // 200
                    game.getMouse(cellX, cellY, player)
                    if game.isGameOver:
                        playing = 'False'
                        send_data = '{}-{}-{}-{}'.format(cellX,
                        cellY, 'yourTurn',
                        playing).encode()
                        conn.send(send_data)
                        turn = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and game.isGameOver:
                    game.clear()
                    game.isGameOver = False
                    playing = 'True'
                elif event.key == pygame.K_ESCAPE:
                    running = False
        surface.fill((0, 0, 0))
        game.draw(surface)
        pygame.display.flip()