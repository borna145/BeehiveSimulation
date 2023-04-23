#include "Map.h"

Map::Map(const sf::Texture& texture, const sf::Vector2f& position)
    : sprite(texture) {
    setPosition(position);
}

void Map::move(const sf::Vector2f& offset) {
    sprite.move(offset);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(sprite, states);
}
