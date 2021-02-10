<<<<<<< HEAD
#include "game_resources.h"

#include <QFile>
#include <cassert>

game_resources::game_resources()
{
  {
    const QString filename{"rocket_sprite.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_rocket.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  {
    const QString filename{"franjo.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_franjo.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  {
    const QString filename{"cat.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_cat.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  {
    /*
    const QString filename{"heterogenous_landscape.jpg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_heterogenous_landscape.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
    */
    sf::Image image;
    const int width{256};
    const int height{256};
    image.create(width, height);
    for (int x{0}; x!=width; ++x)
    {
      for (int y{0}; y!=height; ++y)
      {
        const sf::Uint8 r{static_cast<sf::Uint8>((x * 16) % 256)};
        const sf::Uint8 g{static_cast<sf::Uint8>((y * 16)  % 256)};
        const sf::Uint8 b{static_cast<sf::Uint8>((((x + y) * 16) % 256))};
        image.setPixel(
          static_cast<unsigned int>(x),
          static_cast<unsigned int>(y),
          sf::Color(r, g, b)
        );
      }
    }
    m_heterogenous_landscape.loadFromImage(image);
  }
  {
    const QString filename{"grass_landscape.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_grass_landscape.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  {
    const QString filename{"player_sprite.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_player_sprite.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  /// Load font file
  {
    const QString filename{"arial.ttf"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_font.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find font file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }


#ifndef IS_ON_TRAVIS
  // Playing sound on Travis gives thousands of error lines, which causes the
  // build to fail
  {
    const QString filename{"ninja_gods.ogg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_ninja_gods.openFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find sound file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
#endif // IS_ON_TRAVIS
#ifndef IS_ON_TRAVIS
  // Playing sound on Travis gives thousands of error lines, which causes the
  // build to fail
  // load menu music "wonderland"
  {
    const QString filename{"wonderland.ogg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_wonderland.openFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find sound file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
#endif // IS_ON_TRAVIS
#ifndef IS_ON_TRAVIS
  // Playing sound on Travis gives thousands of error lines, which causes the
  // build to fail
  // load sound for shooting
  {
    const QString filename{"shoot.ogg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_shoot.openFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find sound file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
#endif // IS_ON_TRAVIS
#ifndef IS_ON_TRAVIS
  // Playing sound on Travis gives thousands of error lines, which causes the
  // build to fail
  // load sound for bumping into something/someone
  {
    const QString filename{"bump.ogg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_bump.openFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find sound file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
#endif // IS_ON_TRAVIS
}

void test_game_resources()
{
  game_resources g;
  assert(g.get_heterogenous_landscape().getSize().x > 0.0);


  #ifdef FIX_ISSUE_136
  assert(g.get_sound(sound_type::shoot).getDuration().asMicroseconds() > 0.0);
  #endif
}
=======
#include "game_resources.h"

#include <QFile>
#include <cassert>

game_resources::game_resources()
{
  {
    const QString filename{"rocket_sprite.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_rocket.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  {
    const QString filename{"franjo.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_franjo.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  {
    const QString filename{"cat.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_cat.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  {
    /*
    const QString filename{"heterogenous_landscape.jpg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_heterogenous_landscape.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
    */
    sf::Image image;
    const int width{256};
    const int height{256};
    image.create(width, height);
    for (int x{0}; x!=width; ++x)
    {
      for (int y{0}; y!=height; ++y)
      {
        const sf::Uint8 r{static_cast<sf::Uint8>((x * 16) % 256)};
        const sf::Uint8 g{static_cast<sf::Uint8>((y * 16)  % 256)};
        const sf::Uint8 b{static_cast<sf::Uint8>((((x + y) * 16) % 256))};
        image.setPixel(
          static_cast<unsigned int>(x),
          static_cast<unsigned int>(y),
          sf::Color(r, g, b)
        );
      }
    }
    m_heterogenous_landscape.loadFromImage(image);
  }
  {
    const QString filename{"grass_landscape.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_grass_landscape.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  {
    const QString filename{"player_sprite.png"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_player_sprite.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find image file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
  /// Load font file
  {
    const QString filename{"arial.ttf"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_font.loadFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find font file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }


#ifndef IS_ON_TRAVIS
  // Playing sound on Travis gives thousands of error lines, which causes the
  // build to fail
  {
    const QString filename{"ninja_gods.ogg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_ninja_gods.openFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find sound file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
#endif // IS_ON_TRAVIS
#ifndef IS_ON_TRAVIS
  // Playing sound on Travis gives thousands of error lines, which causes the
  // build to fail
  // load menu music "wonderland"
  {
    const QString filename{"wonderland.ogg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_wonderland.openFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find sound file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
#endif // IS_ON_TRAVIS
#ifndef IS_ON_TRAVIS
  // Playing sound on Travis gives thousands of error lines, which causes the
  // build to fail
  // load sound for shooting
  {
    const QString filename{"shoot.ogg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_shoot.openFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find sound file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
#endif // IS_ON_TRAVIS
#ifndef IS_ON_TRAVIS
  // Playing sound on Travis gives thousands of error lines, which causes the
  // build to fail
  // load sound for bumping into something/someone
  {
    const QString filename{"bump.ogg"};
    QFile f(":/" + filename);
    f.copy(filename);
    if (!m_bump.openFromFile(filename.toStdString()))
    {
      QString msg{"Cannot find sound file '" + filename + "'"};
      throw std::runtime_error(msg.toStdString());
    }
  }
#endif // IS_ON_TRAVIS

}

#ifndef IS_ON_TRAVIS
  /// Get sound and specify which sound to get
sf::Music& game_resources::get_sound(sound_type sound)
{
  switch (sound) {
    case sound_type::bump :
      return m_bump;
    case sound_type::shoot :
      return m_shoot;
    default:
      return m_shoot;
    }
}
#endif // IS_ON_TRAVIS

void test_game_resources()
{
  game_resources g;
  assert(g.get_heterogenous_landscape().getSize().x > 0.0);


  assert(g.get_sound(sound_type::shoot).getDuration().asMicroseconds() > 0.0);

}
>>>>>>> 910232fad93e4d4c43dad27cd43218000658e488
