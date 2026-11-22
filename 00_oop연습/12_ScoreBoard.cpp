
#include <cstring>
#include <iostream>

static void SetCharMember(char* dest, const char* input)
{
    size_t length = strlen(input);
    strncpy(dest, input, length);
    dest[length] = '\0';
}

class Player
{
public:
    Player()
    {
    }

    ~Player()
    {
    }

    void SetName(const char* name)
    {
        SetCharMember(Name, name);
    }

    void SetId(const char* id)
    {
        SetCharMember(Id, id);
    }

    void SetTeam(const char* team)
    {
        SetCharMember(Team, team);
    }

    void SetScore(int score)
    {
        Score = score;
    }

    int GetScore()
    {
        return Score;
    }

    void Print()
    {
        std::cout << "- Player: " << Name << " (Team " << Team << ") Score: " << Score << "\n";
    }

private:
    char Name[256] = "";
    char Id[256] = "";
    char Team[256] = "";
    int Score = 0;
};

class ScoreBoard
{
public:
    ScoreBoard()
    {
    }

    ~ScoreBoard()
    {
    }

    void AddPlayer(Player* player)
    {
        Players.push_back(player);
    }

    void Print()
    {
        for (int i = 0; i < Players.size(); i++)
        {
            Players[i]->Print();
        }

        std::cout << "Average: " << GetAverage();
    }
private:
    int GetAverage()
    {
        int sum = 0;
        for (int i = 0; i < Players.size(); i++)
        {
            sum += Players[i]->GetScore();
        }

        return sum / Players.size();
    }
    std::vector<Player*> Players;
};

int main()
{
    Player A;
    A.SetName("John");
    A.SetTeam("A");
    A.SetScore(80);

    Player B;
    B.SetName("Mary");
    B.SetTeam("B");
    B.SetScore(90);

    ScoreBoard board;
    board.AddPlayer(&A);
    board.AddPlayer(&B);

    board.Print();
    return 0;
}