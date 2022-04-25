#include <iostream>



class Sky
{
private:
  static const int skySize = 10;
  char m_Sky[skySize][skySize]{};

public:
  explicit Sky()
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
    for (auto & i : m_Sky)
    {
      for (char j : i)
      {
        std::cout << j;
      }
      std::cout << std::endl;
    }
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
