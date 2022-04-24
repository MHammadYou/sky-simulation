#include <iostream>



class Sky
{
private:
  static const int skySize = 10;
  char m_Sky[skySize][skySize]{};

public:
  Sky()
  {
    for (auto & i : m_Sky)
    {
      for (char & j : i)
      {
        j = '.';
      }
    }
  }

  void logSky()
  {
    for (int i = 0; i < skySize; i++)
    {
      for (int j = 0; j < skySize; j++)
      {
        std::cout << m_Sky[i][j];
      }
      std::cout << std::endl;
    }
  }
};


int main() {
  Sky sky{};

  sky.logSky();
}
