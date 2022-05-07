#include <iostream>
#include <chrono>
#include <thread>


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
};



class Sky
{
private:
  static const int skySize = 20;
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
    m_Sky[0][6]->makeHash();
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
    for (int i = skySize - 1; i > -1 ; i--)
    {
      for (int j = skySize - 1; j > 0; j--)
      {
        if (m_Sky[i][j]->getState() == " # ")
        {
          // Fix starts move downward after one complete cycle
          m_Sky[i][j]->makeDot();
          m_Sky[i][j+1]->makeHash();
          std::cout << i << " " << j+1 << std::endl;

        }
      }
    }
//    logSky();
  }
};
//
//
//void nextFrame(Sky* sky)
//{
//  using namespace std::chrono_literals;
//  std::this_thread::sleep_for(250ms);
//  sky->nextFrame();
//
//}

int main()
{
  Sky sky{};
//  sky.createSun();
  sky.logSky();
  for (int i = 0; i < 15; i++)
  {
//    nextFrame(&sky);
//    using namespace std::chrono_literals;
//    std::this_thread::sleep_for(250ms);
    sky.nextFrame();
  }
  sky.logSky();
}


