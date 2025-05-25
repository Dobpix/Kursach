#include "GameServer.h"

GameServer::GameServer(Game* game, uint16_t port)
    : webServer(port), game(game) {}

void GameServer::begin() {
    webServer.on("/", [this]() { handleRoot(); });
    webServer.on("/move", [this]() { handleMove(); });
    webServer.onNotFound([this]() { handleNotFound(); });
    webServer.begin();
}

void GameServer::handleClient() {
    webServer.handleClient();
}

void GameServer::handleRoot() {
    webServer.send(200, "text/html", generateHTML());
}

void GameServer::handleMove() {
    if (webServer.hasArg("dir")) {
        int dir = webServer.arg("dir").toInt();
        game->step(dir);
    }
    webServer.sendHeader("Location", "/");
    webServer.send(303);
}

void GameServer::handleNotFound() {
    webServer.send(404, "text/plain", "Not found");
}

String GameServer::generateHTML() {
    Player* player = game->getPlayer();
    Labyrinth* lab = game->getLabyrinth();
    String html = "<html><head><meta charset='utf-8'><meta http-equiv='refresh' content='2'><title>Maze Game</title></head><body>";
    html += "<h2>Maze Game</h2>";
    html += "<p>Score: " + String(player->getScore()) + "</p>";
    html += "<table border='1' cellpadding='3' cellspacing='0'>";
    for (int i = 0; i < ROWS; i++) {
        html += "<tr>";
        for (int j = 0; j < COLS; j++) {
            String cell;
            if (player->getX() == i && player->getY() == j) cell = "🧑";
            else if (lab->isWall(i, j)) cell = "⬛";
            else if (lab->isCoin(i, j)) cell = "🟡";
            else if (lab->isEnemy(i, j)) cell = "👾";
            else if (lab->isFinish(i, j)) cell = "🏁";
            else cell = "⬜";
            html += "<td align='center'>" + cell + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";
    html += "<br>";
    html += "<form action='/move' method='get'>";
    html += "<button name='dir' value='1'>⬆️</button><br>";
    html += "<button name='dir' value='3'>⬅️</button>";
    html += "<button name='dir' value='2'>⬇️</button>";
    html += "<button name='dir' value='4'>➡️</button>";
    html += "</form>";
    if (game->isWin()) html += "<h3>Победа!</h3>";
    if (game->isGameOver()) html += "<h3>Проигрыш!</h3>";
    html += "</body></html>";
    return html;
}