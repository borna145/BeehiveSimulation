#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>

class Map : public sf::Drawable, public sf::Transformable {
public:
    Map(const sf::Texture& texture, const sf::Vector2f& position);
    void move(const sf::Vector2f& offset);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Sprite sprite;
};

#endif
