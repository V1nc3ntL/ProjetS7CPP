#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1350, 591), "DYSTOPIA");
    //sf::CircleShape shape(100.f);
    sf::Texture Background;
    if(!Background.loadFromFile("Background.jpg")){
        printf("Erreur : pas de background trouve\n");
    }
    sf::Sprite s_bg;
    s_bg.setTexture(Background);
    s_bg.setScale(1,1);

    sf::Font fontTitre;
    if(!fontTitre.loadFromFile("Insomnia.ttf")){
         printf("Erreur : pas de font trouve\n");
    }
    sf::Text Titre("DYSTOPIA",fontTitre,50);
    Titre.setFont(fontTitre);
    Titre.setFillColor(sf::Color::Black);
    Titre.setPosition(450, 59.1);
    //shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(s_bg);
        window.draw(Titre);
        window.display();
    }

    return 0;
}
