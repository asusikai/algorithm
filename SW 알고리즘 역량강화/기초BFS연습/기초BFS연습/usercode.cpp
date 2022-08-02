
int map_copy[11][11];
int map_size_copy;

void bfs_init(int map_size, int map[10][10]) {

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {

            map_copy[i][j] = 1;
        }
    }

    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {

            map_copy[i + 1][j + 1] = map[i][j];
        }
    }

    for (int i = 0; i <= map_size; i++) {
        for (int j = 0; j <= map_size; j++) {

        }

    }

    map_size_copy = map_size;
}

int front;
int rear;
int que[100][2];
int distance[11][11];

int bfs(int x1, int y1, int x2, int y2) {

    bool visited[11][11] = { false };

    int front = -1;
    int rear = -1;

    for (int i = 1; i <= map_size_copy; i++) {
        for (int j = 1; j <= map_size_copy; j++) {
            distance[i][j] = 100;
        }
    }

    ++rear;
    que[rear][0] = x1;
    que[rear][1] = y1;


    distance[y1][x1] = 0;
    visited[y1][x1] = true;

    while (front != rear) {
        int curr[2];
        ++front;
        curr[0] = que[front][0];
        curr[1] = que[front][1];


        //up
        if (curr[1] > 1 && curr[0] > 1 && map_copy[curr[1] - 1][curr[0]] == 0 && !visited[curr[1] - 1][curr[0]]) {
            ++rear;
            que[rear][0] = curr[0];
            que[rear][1] = curr[1] - 1;
            distance[curr[1] - 1][curr[0]] = distance[curr[1]][curr[0]] + 1;
            visited[curr[1] - 1][curr[0]] = true;
        }
        //down
        if (curr[1] < map_size_copy && map_copy[curr[1] + 1][curr[0]] == 0 && !visited[curr[1] + 1][curr[0]]) {
            ++rear;
            que[rear][0] = curr[0];
            que[rear][1] = curr[1] + 1;
            distance[curr[1] + 1][curr[0]] = distance[curr[1]][curr[0]] + 1;
            visited[curr[1] + 1][curr[0]] = true;
        }

        //left
        if (curr[0] > 1 && map_copy[curr[1]][curr[0] - 1] == 0 && !visited[curr[1]][curr[0] - 1]) {
            ++rear;
            que[rear][0] = curr[0] - 1;
            que[rear][1] = curr[1];
            distance[curr[1]][curr[0] - 1] = distance[curr[1]][curr[0]] + 1;
            visited[curr[1]][curr[0] - 1] = true;
        }
        //right
        if (curr[0] < map_size_copy && map_copy[curr[1]][curr[0] + 1] == 0 && !visited[curr[1]][curr[0] + 1]) {
            ++rear;
            que[rear][0] = curr[0] + 1;
            que[rear][1] = curr[1];
            distance[curr[1]][curr[0] + 1] = distance[curr[1]][curr[0]] + 1;
            visited[curr[1]][curr[0] + 1] = true;
        }

    }

    for (int i = 1; i <= map_size_copy; i++) {
        for (int j = 1; j <= map_size_copy; j++) {

        }

    }

    if (distance[y2][x2] == 100) {
        return -1;
    }

    else {

        return distance[y2][x2];
    }
}