#include "tools.h"
#include "setup.h"
#include "score_largestNumber.h"
#include "ready_to_pop.h"
#include "control.h"
#include "direction.h"
#include <windows.h>
#include <vector>

int main()
{
    setWindow();
    while (true)
    {
        drawFrame();

        int content[16] = {0};    // create a list of 16 to store number
        int score = 0;

        // play
        while (true)
        {
            int pop = randomNumber();

            // find the amount of available space
            int placeHasNotChosen = 0;
            for (int i = 0; i < 16; i++)
            {
                if (content[i] == 0)
                    placeHasNotChosen++;
            }

            // have available space? If no, exit the loop
            if (placeHasNotChosen <= 0)
                break;

            // get a random place
            int placeChosen = randomPosition(placeHasNotChosen);

            // create a vector store available space
            vector<int> available;
            for (int i = 0; i < 16; i++)
            {
                if (content[i] == 0)
                    available.push_back(i);
            }

            placeChosen = available.at(placeChosen);
            print_pop(placeChosen, pop);
            content[placeChosen] = pop;

            print_score(34,10,score);
            print_largest_number(34,13,content);
            score = ChangeDirection_arrow(content, score);
        }

        // game over
        int tmp = draw_GameOver(score);
        if (tmp == 1)    // again
        {
            system("cls");
            continue;
        }
        else             // exit
            break;
    }

    return 0;
}
