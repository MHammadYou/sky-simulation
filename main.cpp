#include <iostream>



class Sky
{
private:
  static const int skySize = 30;
  std::string m_Sky[skySize][skySize]{};

public:
  explicit Sky()
  {
    for (auto & i : m_Sky)
    {
      for (std::string & j : i)
      {
        j = " . ";
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
      for (std::string j : i)
      {
        std::cout << j;
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
