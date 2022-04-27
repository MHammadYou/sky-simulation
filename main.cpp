#include <iostream>


class Cell
{
private:
  std::string m_State = " . ";
  int m_X, m_Y;

public:

  Cell(int x, int y)
  {
    m_X = x;
    m_Y = y;
  }

  std::string getState()
  {
    return m_State;
  }

  void setState(const std::string& newState)
  {
    m_State = newState;
  }
};



class Sky
{
private:
  static const int skySize = 25;
  Cell* m_Sky[skySize][skySize]{};

public:
  explicit Sky()
  {
    for (int i = 0; i < skySize; i++)
    {
      for (int j = 0; j < skySize; j++)
      {
        m_Sky[i][j] = new Cell(i, j);
      }
    }
  }

  void logSky()
  {
    std::cout << " ";
    for (int i = 0; i < skySize; i++)
    {
      std::cout << "___";
    }
    std::cout << std::endl;
    for (auto & i : m_Sky)
    {
      std::cout << "|";
      for (Cell* j : i)
      {
        std::cout << j->getState();
      }
      std::cout << "|" << std::endl;
    }
    std::cout << " ";
    for (int i = 0; i < skySize; i++)
    {
      std::cout << "___";
    }
    std::cout << std::endl;
  }

  void nextFrame()
  {
    // move next frame
  }
};


int main() {
  Sky sky{};

  sky.logSky();
}
