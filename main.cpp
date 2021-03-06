#include <iostream>
#include <chrono>
#include <thread>
#include <map>
#include <vector>


class Cell
{
private:
  std::string m_State = " . ";
  int m_X, m_Y;

  void setState(const std::string& newState)
  {
    m_State = newState;
  }

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

  void makeDot()
  {
    setState(" . ");
  }

  void makeHash()
  {
    setState(" # ");
  }

  std::map<std::string, int> getPos()
  {
    std::map<std::string, int> pos;
    pos.insert(std::pair<std::string, int>("x", m_X));
    pos.insert(std::pair<std::string, int>("y", m_Y));
    return pos;
  }
};

class Sky
{
private:
  static const int skySize = 10;
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

//    m_Sky[0][0]->makeHash();
//    m_Sky[0][1]->makeHash();
//    m_Sky[0][2]->makeHash();
//    m_Sky[0][3]->makeHash();
//    m_Sky[1][4]->makeHash();
//    m_Sky[0][6]->makeHash();
      m_Sky[0][1]->makeHash();
      m_Sky[0][2]->makeHash();
      m_Sky[0][3]->makeHash();

  }

  void createSun()
  {
    for (int i = 3; i < 6; i++)
    {
      for (int j = 3; j < 6; j++)
      {
        m_Sky[i][j]->makeHash();
      }
    }
  }

  void createMoon()
  {
    m_Sky[1][6]->makeHash();
    m_Sky[1][7]->makeHash();
    m_Sky[2][7]->makeHash();
    m_Sky[3][7]->makeHash();
    m_Sky[3][6]->makeHash();
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
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1000ms);
  }

  void nextFrame()
  {
    for (std::map<std::string, int> star: getStarts())
    {
      if (star["y"]+1 != skySize) {
        m_Sky[star["x"]][star["y"]]->makeDot();
        m_Sky[star["x"]][star["y"]+1]->makeHash();
      } else {
        m_Sky[star["x"]][star["y"]]->makeDot();
        m_Sky[star["x"]][0]->makeHash();
      }
      logSky();
    }
  }

  std::vector<std::map<std::string, int>> getStarts()
  {
    std::vector<std::map<std::string, int>> stars;

    for (int i = skySize - 1; i > -1 ; i--)
    {
      for (int j = skySize - 1; j > -1; j--)
      {
        if (m_Sky[i][j]->getState() == " # ")
        {
          stars.push_back(m_Sky[i][j]->getPos());
        }
      }
    }
    return stars;
  }
};

int main()
{
  Sky sky{};
  sky.logSky();
  for (int i = 0; i < 100; i++)
  {
      sky.nextFrame();
  }
}


