class Robot {
private:
    int x, y;
    int dir;

    int w, h;
    int tot;

public:

    Robot(int width, int height) {
        x = 0;
        y = 0;
        dir = 1;
        w = width;
        h = height;
        tot = 2 * w;
        tot += 2 * (h - 2);
    }
    void step(int num) {
        if(num % tot == 0 && x == 0 && y == 0)
            dir = 2;
        num %= tot;
        while(num) {
            if(dir == 1) {
                int step = w - x - 1;
                step = min(step, num);

                x += step;
                num -= step;
            }
            else if(dir == 0) {
                int step = h - 1 - y;
                step = min(step, num);

                y += step;
                num -= step;
            }
            else if(dir == 3) {
                int step = min(x, num);
                x -= step;
                num -= step;
            }
            else if(dir == 2) {
                int step = min(y, num);
                y -= step;
                num -= step;
            }
            if(num)
                dir = (dir - 1 + 4) % 4;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {

        if(dir == 1) return "East";
        if(dir == 0) return "North";
        if(dir == 3) return "West";

        return "South";
    }
};