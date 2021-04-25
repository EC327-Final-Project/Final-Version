#include<iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include<string>
#include<cmath>


//Ask about postion
// ask about functions and classes
// ask about methods
// as
//General flow

// Create the objects
// Create events
// Check if anything has changed

//Ask how user can increase window 
// class States(){

// };



// Constant button dimensions
const int bwidth = 100;
const int bheight = 30;

// Function for button pressing
bool isMouseOver(sf::RenderWindow &window, sf::RectangleShape &button) {
  // Mouse x and y coords
  int mouseX = sf::Mouse::getPosition(window).x;
  int mouseY = sf::Mouse::getPosition(window).y;

  // Button Start Position coords
  int btnPosX = button.getPosition().x;
  int btnPosY = button.getPosition().y;

  // Button End Position coords
  int btnxPosWidth = button.getPosition().x + bwidth;
  int btnyPosHeight = button.getPosition().y + bheight;

  // Check to see if mouse is within button bounds
  if (mouseX < btnPosX && mouseX > btnPosX - bwidth && mouseY < btnyPosHeight && mouseY > btnPosY) {
    return true;
  }
  return false;
}

int Legal_Function ()
{
 // States and Regions Set-Up
  std::vector<std::string> Regions = {"West Region",
  "South West Region",
  "Mid West Region",
  "South East Region",
  "North East Region"};

  std::vector<std::string> Region_West = {
    "Colorado",
    "Wyoming",
    "Montana",
    "Idaho",
    "Washington",
    "Oregon",
    "Utah",
    "Nevada",
    "California",
    "Alaska",
    "Hawaii",
  };

  std::vector<std::string> Region_SouthWest = {
    "Texas",
    "Oklahoma",
    "New Mexico",
    "Arizona",
  };

  std::vector<std::string> Region_MidWest = {
    "Ohio",
    "Indiana",
    "Michigan",
    "Illinois",
    "Missouri",
    "Wisconsin",
    "Minnesota",
    "Iowa",
    "Kansas",
    "Nebraska",
    "South Dakota",
    "North Dakota",
    };

  std::vector<std::string> Region_SouthEast = {
    "West Virginia",
    "Virginia",
    "Kentucky",
    "Tennessee",
    "North Carolina",
    "South Carolina",
    "Georgia",
    "Alabama",
    "Mississippi",
    "Arkansas",
    "Louisiana",
    "Florida"
  };

  std::vector<std::string> Region_NorthEast = {
    "Maine",
    "Massassachusetts",
    "Rhode Island",
    "Connecticut",
    "New Hampshire",
    "Vermont",
    "New York",
    "Pennsylvania",
    "New Jersey",
    "Delaware",
    "Maryland"
  };

  //Not my Portion

  // Set window and font
  sf::RenderWindow window(sf::VideoMode(500, 500), "Marijuana");
  sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");
  


  // Title declarations
  sf::Text title;
  title.setFont(font);
  title.setFillColor(sf::Color::White);
  title.setOutlineColor(sf::Color(39, 121, 21));
  title.setOutlineThickness(1);
  title.setPosition(145, 10);

  // Home button and label declarations
  sf::RectangleShape home(sf::Vector2f(bheight, bwidth));
  home.setPosition(300, 10);
  home.setFillColor(sf::Color::White);
  home.setRotation(90);
  sf::Text homelabel;
  homelabel.setFont(font);
  homelabel.setFillColor(sf::Color(39, 121, 21));
  homelabel.setOutlineColor(sf::Color::Black);
  homelabel.setOutlineThickness(0.2);
  homelabel.setPosition(210, 17);
  homelabel.setString("Back to Home");
  homelabel.setCharacterSize(12);

  //My portion of the code

    // Map Texture Set-Up;

  sf::Texture US_Map;
  if(!US_Map.loadFromFile("us_states_map_regions_sm.jpg"))
  {
   return 1;
  }

  sf::Sprite USA;
  USA.setTexture(US_Map);

  //Ask user to select a State
  sf::Text Ask_State;
  Ask_State.setFont(font);
  Ask_State.setFillColor(sf::Color::White);
  Ask_State.setOutlineColor(sf::Color(39, 121, 21));
  Ask_State.setCharacterSize(20);
  Ask_State.setOutlineThickness(.5);
  Ask_State.setPosition(120, 110); //Run this in the actual window section
  Ask_State.setString("Please select your state:"); 

  //State
  sf::Text State;
  State.setFont(font);
  State.setFillColor(sf::Color::White);
  State.setOutlineColor(sf::Color(39, 121, 21));
  State.setOutlineThickness(.5);
  State.setPosition(150, 60);

    // My Window's Question
  sf::Text Question;
  Question.setFont(font);
  Question.setFillColor(sf::Color::White);
  Question.setOutlineColor(sf::Color(39, 121, 21));
  Question.setCharacterSize(20);
  Question.setOutlineThickness(1);
  Question.setPosition(150, 50);
  Question.setString("Click a Region \n to find how legal \n Marijuana is");

  // Map button and label declarations
  sf::RectangleShape mapbutton(sf::Vector2f(bheight, bwidth));
  mapbutton.setPosition(300, 10);
  mapbutton.setFillColor(sf::Color::White);
  mapbutton.setRotation(90);
  
  sf::Text maplabel;
  maplabel.setFont(font);
  maplabel.setFillColor(sf::Color(39, 121, 21));
  maplabel.setOutlineColor(sf::Color::Black);
  maplabel.setOutlineThickness(0.2);
  maplabel.setString("Return to /n map");
  maplabel.setPosition(210, 50);

  //Legality need a class that does this shit
  sf::RectangleShape Legality(sf::Vector2f(bheight, bwidth));
  Legality.setPosition(150, 250);
  Legality.setFillColor(sf::Color::White);
  Legality.setRotation(90);
  sf::Text leglabel;
  leglabel.setFont(font);
  leglabel.setFillColor(sf::Color(39, 121, 21));
  leglabel.setOutlineColor(sf::Color::Black);
  leglabel.setOutlineThickness(0.2);
  leglabel.setPosition(150+15-bwidth, 247); // Weird numbers for formatting

  //State Labels
  sf::Text StateLabel1;
  StateLabel1.setFont(font);
  StateLabel1.setFillColor(sf::Color(39, 121, 21));
  StateLabel1.setOutlineColor(sf::Color::Black);
  StateLabel1.setOutlineThickness(0.2);
  StateLabel1.setCharacterSize(12);

  sf::Text StateLabel2;
  StateLabel2.setFont(font);
  StateLabel2.setFillColor(sf::Color(39, 121, 21));
  StateLabel2.setOutlineColor(sf::Color::Black);
  StateLabel2.setOutlineThickness(0.2);
  StateLabel2.setCharacterSize(12);

  sf::Text StateLabel3;
  StateLabel3.setFont(font);
  StateLabel3.setFillColor(sf::Color(39, 121, 21));
  StateLabel3.setOutlineColor(sf::Color::Black);
  StateLabel3.setOutlineThickness(0.2);
  StateLabel3.setCharacterSize(12);

  sf::Text StateLabel4;
  StateLabel4.setFont(font);
  StateLabel4.setFillColor(sf::Color(39, 121, 21));
  StateLabel4.setOutlineColor(sf::Color::Black);
  StateLabel4.setOutlineThickness(0.2);
  StateLabel4.setCharacterSize(12);

  sf::Text StateLabel5;
  StateLabel5.setFont(font);
  StateLabel5.setFillColor(sf::Color(39, 121, 21));
  StateLabel5.setOutlineColor(sf::Color::Black);
  StateLabel5.setOutlineThickness(0.2);
  StateLabel5.setCharacterSize(12);

  sf::Text StateLabel6;
  StateLabel6.setFont(font);
  StateLabel6.setFillColor(sf::Color(39, 121, 21));
  StateLabel6.setOutlineColor(sf::Color::Black);
  StateLabel6.setOutlineThickness(0.2);
  StateLabel6.setCharacterSize(12);

  sf::Text StateLabel7;
  StateLabel7.setFont(font);
  StateLabel7.setFillColor(sf::Color(39, 121, 21));
  StateLabel7.setOutlineColor(sf::Color::Black);
  StateLabel7.setOutlineThickness(0.2);
  StateLabel7.setCharacterSize(12);

  sf::Text StateLabel8;
  StateLabel8.setFont(font);
  StateLabel8.setFillColor(sf::Color(39, 121, 21));
  StateLabel8.setOutlineColor(sf::Color::Black);
  StateLabel8.setOutlineThickness(0.2);
  StateLabel8.setCharacterSize(12);

  sf::Text StateLabel9;
  StateLabel9.setFont(font);
  StateLabel9.setFillColor(sf::Color(39, 121, 21));
  StateLabel9.setOutlineColor(sf::Color::Black);
  StateLabel9.setOutlineThickness(0.2);
  StateLabel9.setCharacterSize(12);

  sf::Text StateLabel10;
  StateLabel10.setFont(font);
  StateLabel10.setFillColor(sf::Color(39, 121, 21));
  StateLabel10.setOutlineColor(sf::Color::Black);
  StateLabel10.setOutlineThickness(0.2);
  StateLabel10.setCharacterSize(12);

  sf::Text StateLabel11;
  StateLabel11.setFont(font);
  StateLabel11.setFillColor(sf::Color(39, 121, 21));
  StateLabel11.setOutlineColor(sf::Color::Black);
  StateLabel11.setOutlineThickness(0.2);
  StateLabel11.setCharacterSize(12);

  sf::Text StateLabel12;
  StateLabel12.setFont(font);
  StateLabel12.setFillColor(sf::Color(39, 121, 21));
  StateLabel12.setOutlineColor(sf::Color::Black);
  StateLabel12.setOutlineThickness(0.2);
  StateLabel12.setCharacterSize(12);

  sf::Text StateLabel13;
  StateLabel13.setFont(font);
  StateLabel13.setFillColor(sf::Color(39, 121, 21));
  StateLabel13.setOutlineColor(sf::Color::Black);
  StateLabel13.setOutlineThickness(0.2);
  StateLabel13.setCharacterSize(12);

  //Boxes for the individual States really need a class for this
  sf::RectangleShape Box1(sf::Vector2f(bheight, bwidth));
  Box1.setRotation(90);
  Box1.setFillColor(sf::Color::White);

  sf::RectangleShape Box2(sf::Vector2f(bheight, bwidth));
  Box2.setRotation(90);
  Box2.setFillColor(sf::Color::White);

  sf::RectangleShape Box3(sf::Vector2f(bheight, bwidth));
  Box3.setRotation(90);
  Box3.setFillColor(sf::Color::White);

  sf::RectangleShape Box4(sf::Vector2f(bheight, bwidth));
  Box4.setRotation(90);
  Box4.setFillColor(sf::Color::White);
  sf::RectangleShape Box5(sf::Vector2f(bheight, bwidth));
  Box5.setRotation(90);
  Box5.setFillColor(sf::Color::White);

  sf::RectangleShape Box6(sf::Vector2f(bheight, bwidth));
  Box6.setRotation(90);
  Box6.setFillColor(sf::Color::White);

  sf::RectangleShape Box7(sf::Vector2f(bheight, bwidth));
  Box7.setRotation(90);
  Box7.setFillColor(sf::Color::White);

  sf::RectangleShape Box8(sf::Vector2f(bheight, bwidth));
  Box8.setRotation(90);
  Box8.setFillColor(sf::Color::White);

  sf::RectangleShape Box9(sf::Vector2f(bheight, bwidth));
  Box9.setRotation(90);
  Box9.setFillColor(sf::Color::White);

  sf::RectangleShape Box10(sf::Vector2f(bheight, bwidth));
  Box10.setRotation(90);
  Box10.setFillColor(sf::Color::White);

  sf::RectangleShape Box11(sf::Vector2f(bheight, bwidth));
  Box11.setRotation(90);
  Box11.setFillColor(sf::Color::White);

  sf::RectangleShape Box12(sf::Vector2f(bheight, bwidth));
  Box12.setRotation(90);
  Box12.setFillColor(sf::Color::White);

  sf::RectangleShape Box13(sf::Vector2f(bheight, bwidth));
  Box13.setRotation(90);
  Box13.setFillColor(sf::Color::White);
  
  // You selected response
  sf::Text Selection;
  Selection.setFont(font);
  Selection.setFillColor(sf::Color::White);
  Selection.setOutlineColor(sf::Color(39, 121, 21));
  Selection.setOutlineThickness(.5);
  Selection.setPosition(150, 35);
  Selection.setString("You selected:");

  //Region Fill in
  sf::Text Region;
  Region.setFont(font);
  Region.setFillColor(sf::Color::White);
  Region.setOutlineColor(sf::Color(39, 121, 21));
  Region.setOutlineThickness(.5);
  Region.setPosition(120, 70);


  //Legality Status generation
  sf::Text Category;
  Category.setFont(font);
  Category.setFillColor(sf::Color::White);
  Category.setOutlineColor(sf::Color(39, 121, 21));
  Category.setOutlineThickness(.5);
  Category.setPosition(10, 150);
  Category.setString("Legal: \n \nLegal (medical use only): \n \nIllegal: ");
  //This setString will be in that actual function once we can get the number
  
  //Check Generation
  sf::Sprite Check_Sprite;
  sf::Texture checkmark;
  std::vector<int> Check_X;
  std::vector<int> Check_Y;
  Check_X = {100, 360, 110};
  Check_Y = {130, 210, 270};

  if(!checkmark.loadFromFile("checkmark.png"))
   return 1;

  Check_Sprite.setTexture(checkmark);
  Check_Sprite.setScale(sf::Vector2f(.1,.1));

  // Custom Buttons for the Five Regions need a class for this shit (Change to fifty buttons)
  sf::CircleShape West(5);
  West.setFillColor(sf::Color(100, 100, 50));

  sf::CircleShape SouthWest(5);
  SouthWest.setFillColor(sf::Color(100, 100, 50));

  sf::CircleShape MidWest(5);
  MidWest.setFillColor(sf::Color(100, 100, 50));
  
  sf::CircleShape SouthEast(5);
  SouthEast.setFillColor(sf::Color(100, 100, 50));

  sf::CircleShape NorthEast(5);
  NorthEast.setFillColor(sf::Color(100, 100, 50));

  // Framerate limit and declaring event for use
  window.setFramerateLimit(5);
  sf::Event event;

  // Window operations

  while (window.isOpen()) 
  {

    // Set all objects into SFML
    title.setString("Marijuana Info");
    window.draw(title);

    window.draw(Legality);
    leglabel.setString("Locations");
    leglabel.setCharacterSize(15);
    window.draw(leglabel);

    window.display();

    window.clear(sf::Color(137, 197, 125));

    // Count for back to home button push
    int count_home = 0; //change to count_home
    int count_map = 0;
    int count_region = 0;

    //Count for moving to next slide
    int count_West = 0;
    int count_SouthWest = 0;
    int count_MidWest = 0;
    int count_SouthEast = 0;
    int count_NorthEast = 0;

    //Count for each state

    int count_State1 = 0;
    int count_State2 = 0;
    int count_State3 = 0;
    int count_State4 = 0;
    int count_State5 = 0;
    int count_State6 = 0;
    int count_State7 = 0;
    int count_State8 = 0;
    int count_State9 = 0;
    int count_State10 = 0;
    int count_State11 = 0;
    int count_State12 = 0;
    int count_State13 = 0;


    // Check for events (window closing or button pushing)
    sf::Event event;

    while (window.pollEvent(event)) 
    {
      // Close window/program on exit click (top right 'x')
      if (event.type == sf::Event::Closed) 
        window.close();
      
      auto Pressing = sf::Event::MouseButtonPressed;

      if(Pressing)
      {
        //Legality Section
        if (isMouseOver(window, Legality))
        {
          Legality.setFillColor(sf::Color::Black);

          if (event.mouseButton.button == sf::Mouse::Left) 
          {
            while(window.isOpen()) 
            {
              //Need a function that auto does the close option

              window.clear(sf::Color(137, 197, 125));
              window.draw(home);
              homelabel.setString("Back to Home");
              homelabel.setCharacterSize(12);
              window.draw(homelabel);
              USA.setPosition(sf::Vector2f(30, 150));
                
              window.draw(USA);
              window.draw(Question);

              //For loop that would draw each dot in the right place -- need tips on getting correct spacing
              
              West.setPosition(170,200);
              SouthWest.setPosition(170,300);
              MidWest.setPosition(250,200);
              SouthEast.setPosition(300,300);
              NorthEast.setPosition(400,250);

              window.draw(West);
              window.draw(SouthWest);
              window.draw(MidWest);
              window.draw(SouthEast);
              window.draw(NorthEast);

              window.display();

              while (window.pollEvent(event)) 
              {

              if (event.type == sf::Event::Closed)
                {
                  window.close();
                }

                if (event.type == sf::Event::MouseButtonPressed) 
                  {
                     if (isMouseOver(window, home)) 
                      {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                        {
                          count_home++;
                          break;
                        }
                }

                double mouseX =  event.mouseButton.x;
                double mouseY = event.mouseButton.y;

                auto locationWest = West.getPosition();
                double locationXWest = locationWest.x+5;
                double locationYWest = locationWest.y+5;


                double distanceWest = std::pow(mouseX-locationXWest,2) + std::pow(mouseY-locationYWest,2);

                double cr_West = West.getRadius(); 
                  
                  
                if(distanceWest < (double)(cr_West * cr_West))
                {
                count_West++;
                break;
                // std::cout << " " << distance << " " << cr*cr << std::endl;
                }

                auto locationSouthWest = SouthWest.getPosition();
                double locationXSouthWest = locationSouthWest.x+5;
                double locationYSouthWest = locationSouthWest.y+5;

                double distanceSouthWest = std::pow(mouseX-locationXSouthWest,2) + std::pow(mouseY-locationYSouthWest,2);

                double cr_SouthWest = SouthWest.getRadius();

                if(distanceSouthWest < (double)(cr_SouthWest * cr_SouthWest))
                {
                count_SouthWest++;
                break;
                }

                auto locationMidWest = MidWest.getPosition();
                double locationXMidWest = locationMidWest.x+5;
                double locationYMidWest = locationMidWest.y+5;

                double distanceMidWest = std::pow(mouseX-locationXMidWest,2) + std::pow(mouseY-locationYMidWest,2);

                double cr_MidWest = MidWest.getRadius();

                if(distanceMidWest < (double)(cr_MidWest * cr_MidWest))
                {
                count_MidWest++;
                break;
                }

                auto locationSouthEast = SouthEast.getPosition();
                double locationXSouthEast = locationSouthEast.x+5;
                double locationYSouthEast = locationSouthEast.y+5;

                double distanceSouthEast = std::pow(mouseX-locationXSouthEast,2) + std::pow(mouseY-locationYSouthEast,2);

                double cr_SouthEast = SouthEast.getRadius();

                if(distanceSouthEast < (double)(pow(cr_SouthEast,2)))
                {
                count_SouthEast++;
                break;
                }

                auto locationNorthEast = NorthEast.getPosition();
                double locationXNorthEast = locationNorthEast.x+5;
                double locationYNorthEast = locationNorthEast.y+5;

                double distanceNorthEast = std::pow(mouseX-locationXNorthEast,2) + std::pow(mouseY-locationYNorthEast,2);

                double cr_NorthEast = NorthEast.getRadius();

                if(distanceNorthEast < (double)(pow(cr_NorthEast,2)))
                {
                count_NorthEast++;
                break;
                }
              
              }

            } // End of the events; we check if anything has changed


            if (count_home > 0) 
            {
              window.clear(sf::Color(137, 197, 125));
              break;
            }

//WEST STARTS HERE


            if (count_West > 0)
            {
              //string for vector<>
              window.clear(sf::Color(137, 197, 125));
              Region.setString(Regions.at(0));
              window.draw(home);
              window.draw(homelabel);
              window.draw(Region);
              window.draw(Selection);
              window.draw(Ask_State);

              //Set Each State's String

              StateLabel1.setString(Region_West.at(0));
              StateLabel2.setString(Region_West.at(1));
              StateLabel3.setString(Region_West.at(2));
              StateLabel4.setString(Region_West.at(3));
              StateLabel5.setString(Region_West.at(4));
              StateLabel6.setString(Region_West.at(5));
              StateLabel7.setString(Region_West.at(6));
              StateLabel8.setString(Region_West.at(7));
              StateLabel9.setString(Region_West.at(8));
              StateLabel10.setString(Region_West.at(9));
              StateLabel11.setString(Region_West.at(10));

              // Draw Each Box and button for West
              Box1.setPosition(170,150);
              Box2.setPosition(370,150);
              Box3.setPosition(170,200);
              Box4.setPosition(370,200);
              Box5.setPosition(170,250);
              Box6.setPosition(370,250);
              Box7.setPosition(170,300);
              Box8.setPosition(370,300);
              Box9.setPosition(170,350);
              Box10.setPosition(370,350);
              Box11.setPosition(270,400);
              
              //Draw Each State
              StateLabel1.setPosition(170-bwidth,150);
              StateLabel2.setPosition(370-bwidth,150);
              StateLabel3.setPosition(170-bwidth,200);
              StateLabel4.setPosition(370-bwidth,200);
              StateLabel5.setPosition(170-bwidth,250);
              StateLabel6.setPosition(370-bwidth,250);
              StateLabel7.setPosition(170-bwidth,300);
              StateLabel8.setPosition(370-bwidth,300);
              StateLabel9.setPosition(170-bwidth,350);
              StateLabel10.setPosition(370-bwidth,350);
              StateLabel11.setPosition(270-bwidth,400);

              window.draw(Box1);
              window.draw(Box2);
              window.draw(Box3);
              window.draw(Box4);
              window.draw(Box5);
              window.draw(Box6);
              window.draw(Box7);
              window.draw(Box8);
              window.draw(Box9);
              window.draw(Box10);
              window.draw(Box11);


              window.draw(StateLabel1);
              window.draw(StateLabel2);
              window.draw(StateLabel3);
              window.draw(StateLabel4);
              window.draw(StateLabel5);
              window.draw(StateLabel6);
              window.draw(StateLabel7);
              window.draw(StateLabel8);
              window.draw(StateLabel9);
              window.draw(StateLabel10);
              window.draw(StateLabel11);

              window.display();

              while(window.isOpen())
              {
                while (window.pollEvent(event)) 
                {

                  if (event.type == sf::Event::Closed) //function for close needed
                  {
                    window.close();
                  }

                  if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                  {
                    if (isMouseOver(window, home)) 
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_home++;
                        break;
                      }

                    }

                    //Now we check for each Box available

                    if(isMouseOver(window, Box1))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State1++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box2))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State2++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box3))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State3++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box4))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State4++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box5))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State5++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box6))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State6++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box7))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State7++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box8))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State8++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box9))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State9++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box10))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State10++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box11))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State11++;
                        break;
                      }
                    }

                  }
                }

                //This is when we draw new windows

                if (count_home > 0) //Implement this in a function
                {
                  window.clear(sf::Color(137, 197, 125));
                  break;
                }

                if (count_State1 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_West.at(0));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state1 statement

                if (count_State2 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_West.at(1));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state2 statement

                if (count_State3 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_West.at(2));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state3 statement

                if (count_State4 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_West.at(3));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state4 statement

                if (count_State5 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_West.at(4));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state5 statement
                if (count_State6 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_West.at(5));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state6 statement

                if (count_State7 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_West.at(6));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state7 statement

                if (count_State8 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_West.at(7));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state8 statement

                if (count_State9 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_West.at(8));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state9 statement 

                if (count_State10> 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_West.at(9));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state10 statement

                if (count_State11 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_West.at(10));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state11 statement   

                if (count_State12 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(3),Check_Y.at(3));
                  State.setString(Region_West.at(0));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state12 statement 
                                                                     

            } //end of while window is open for the region window

          } //end of the if count_West

//WEST ENDS HERE
//SOUTHWEST STARTS HERE

            if (count_SouthWest > 0)
            {
              window.clear(sf::Color(137, 197, 125));
              Region.setString(Regions.at(1));
              window.draw(home);
              window.draw(homelabel);
              window.draw(Region);
              window.draw(Selection);
              window.draw(Ask_State);


              //Set Each State's String

              StateLabel1.setString(Region_SouthWest.at(0));
              StateLabel2.setString(Region_SouthWest.at(1));
              StateLabel3.setString(Region_SouthWest.at(2));
              StateLabel4.setString(Region_SouthWest.at(3));

              // Draw Each Box and button for West
              Box1.setPosition(170,150);
              Box2.setPosition(370,150);
              Box3.setPosition(170,200);
              Box4.setPosition(370,200);
              
              //Draw Each State
              StateLabel1.setPosition(170-bwidth,150);
              StateLabel2.setPosition(370-bwidth,150);
              StateLabel3.setPosition(170-bwidth,200);
              StateLabel4.setPosition(370-bwidth,200);


              window.draw(Box1);
              window.draw(Box2);
              window.draw(Box3);
              window.draw(Box4);



              window.draw(StateLabel1);
              window.draw(StateLabel2);
              window.draw(StateLabel3);
              window.draw(StateLabel4);



              window.display();

              while(window.isOpen())
              {
                while (window.pollEvent(event)) 
                {

                  if (event.type == sf::Event::Closed) //function for close needed
                  {
                    window.close();
                  }

                  if (event.type == sf::Event::MouseButtonPressed) 
                  {
                    if (isMouseOver(window, home)) 
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_home++;
                        break;
                      }
                    }



                    //Now we check for each Box available

                    if(isMouseOver(window, Box1))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State1++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box2))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State2++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box3))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State3++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box4))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State4++;
                        break;
                      }
                    }

                    
                  }
                }

                if (count_home > 0) //Implement this in a function
                {
                  window.clear(sf::Color(137, 197, 125));
                  break;
                }

                if (count_State1 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_SouthWest.at(0));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state1 statement

                if (count_State2 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_SouthWest.at(1));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state2 statement

                if (count_State3 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_SouthWest.at(2));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state3 statement

                if (count_State4 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_SouthWest.at(3));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state4 statement

                }

              } //end of the count for West

//South West ENDS HERE
//Mid West Starts here

            if (count_MidWest > 0)
            {
              window.clear(sf::Color(137, 197, 125));
              Region.setString(Regions.at(2));
              window.draw(home);
              window.draw(Region);
              window.draw(homelabel);
              window.draw(Selection);
              window.draw(Ask_State);
              window.display();

              //Set Each State's String

              StateLabel1.setString(Region_MidWest.at(0));
              StateLabel2.setString(Region_MidWest.at(1));
              StateLabel3.setString(Region_MidWest.at(2));
              StateLabel4.setString(Region_MidWest.at(3));
              StateLabel5.setString(Region_MidWest.at(4));
              StateLabel6.setString(Region_MidWest.at(5));
              StateLabel7.setString(Region_MidWest.at(6));
              StateLabel8.setString(Region_MidWest.at(7));
              StateLabel9.setString(Region_MidWest.at(8));
              StateLabel10.setString(Region_MidWest.at(9));
              StateLabel11.setString(Region_MidWest.at(10));
              StateLabel12.setString(Region_MidWest.at(11));

              // Draw Each Box and button for West
              Box1.setPosition(170,150);
              Box2.setPosition(370,150);
              Box3.setPosition(170,200);
              Box4.setPosition(370,200);
              Box5.setPosition(170,250);
              Box6.setPosition(370,250);
              Box7.setPosition(170,300);
              Box8.setPosition(370,300);
              Box9.setPosition(170,350);
              Box10.setPosition(370,350);
              Box11.setPosition(170,400);
              Box12.setPosition(370,400);
              
              //Draw Each State
              StateLabel1.setPosition(170-bwidth,150);
              StateLabel2.setPosition(370-bwidth,150);
              StateLabel3.setPosition(170-bwidth,200);
              StateLabel4.setPosition(370-bwidth,200);
              StateLabel5.setPosition(170-bwidth,250);
              StateLabel6.setPosition(370-bwidth,250);
              StateLabel7.setPosition(170-bwidth,300);
              StateLabel8.setPosition(370-bwidth,300);
              StateLabel9.setPosition(170-bwidth,350);
              StateLabel10.setPosition(370-bwidth,350);
              StateLabel11.setPosition(170-bwidth,400);
              StateLabel12.setPosition(370-bwidth,400);

              window.draw(Box1);
              window.draw(Box2);
              window.draw(Box3);
              window.draw(Box4);
              window.draw(Box5);
              window.draw(Box6);
              window.draw(Box7);
              window.draw(Box8);
              window.draw(Box9);
              window.draw(Box10);
              window.draw(Box11);
              window.draw(Box12);


              window.draw(StateLabel1);
              window.draw(StateLabel2);
              window.draw(StateLabel3);
              window.draw(StateLabel4);
              window.draw(StateLabel5);
              window.draw(StateLabel6);
              window.draw(StateLabel7);
              window.draw(StateLabel8);
              window.draw(StateLabel9);
              window.draw(StateLabel10);
              window.draw(StateLabel11);
              window.draw(StateLabel12);

              window.display();

              while(window.isOpen())
              {
                while (window.pollEvent(event)) 
                {

                  if (event.type == sf::Event::Closed) //function for close needed
                  {
                    window.close();
                  }

                  if (event.type == sf::Event::MouseButtonPressed) 
                  {
                    if (isMouseOver(window, home)) 
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_home++;
                        break;
                      }

                    }

                    //Now we check for each Box available

                    if(isMouseOver(window, Box1))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State1++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box2))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State2++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box3))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State3++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box4))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State4++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box5))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State5++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box6))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State6++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box7))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State7++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box8))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State8++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box9))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State9++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box10))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State10++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box11))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State11++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box12))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State12++;
                        break;
                      }
                    }
                  }
                }

                if (count_home > 0) //Implement this in a function
                {
                  window.clear(sf::Color(137, 197, 125));
                  break;
                }

                if (count_State1 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_MidWest.at(0));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state1 statement

                if (count_State2 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_MidWest.at(1));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state2 statement

                if (count_State3 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_MidWest.at(2));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state3 statement

                if (count_State4 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_MidWest.at(3));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state4 statement

                if (count_State5 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_MidWest.at(4));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state5 statement
                if (count_State6 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_MidWest.at(5));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state6 statement

                if (count_State7 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_MidWest.at(6));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state7 statement

                if (count_State8 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_MidWest.at(7));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state8 statement

                if (count_State9 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_MidWest.at(8));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state9 statement 

                if (count_State10> 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_MidWest.at(9));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state10 statement

                if (count_State11 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_MidWest.at(10));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state11 statement   

                if (count_State12 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_MidWest.at(11));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state12 statement 

              }

            } //end of the if count three

//MIDWEST ENDS HERE
//SOUTHEAST STARTS HERE

           if (count_SouthEast > 0)
            {
              window.clear(sf::Color(137, 197, 125));
              Region.setString(Regions.at(3));
              window.draw(home);
              window.draw(Region);
              window.draw(homelabel);
              window.draw(Selection);
              window.draw(Ask_State);
              window.display();

              //Set Each State's String

              StateLabel1.setString(Region_SouthEast.at(0));
              StateLabel2.setString(Region_SouthEast.at(1));
              StateLabel3.setString(Region_SouthEast.at(2));
              StateLabel4.setString(Region_SouthEast.at(3));
              StateLabel5.setString(Region_SouthEast.at(4));
              StateLabel6.setString(Region_SouthEast.at(5));
              StateLabel7.setString(Region_SouthEast.at(6));
              StateLabel8.setString(Region_SouthEast.at(7));
              StateLabel9.setString(Region_SouthEast.at(8));
              StateLabel10.setString(Region_SouthEast.at(9));
              StateLabel11.setString(Region_SouthEast.at(10));
              StateLabel12.setString(Region_SouthEast.at(11));

              // Draw Each Box and button for West
              Box1.setPosition(170,150);
              Box2.setPosition(370,150);
              Box3.setPosition(170,200);
              Box4.setPosition(370,200);
              Box5.setPosition(170,250);
              Box6.setPosition(370,250);
              Box7.setPosition(170,300);
              Box8.setPosition(370,300);
              Box9.setPosition(170,350);
              Box10.setPosition(370,350);
              Box11.setPosition(170,400);
              Box12.setPosition(370,400);
              
              //Draw Each State
              StateLabel1.setPosition(170-bwidth,150);
              StateLabel2.setPosition(370-bwidth,150);
              StateLabel3.setPosition(170-bwidth,200);
              StateLabel4.setPosition(370-bwidth,200);
              StateLabel5.setPosition(170-bwidth,250);
              StateLabel6.setPosition(370-bwidth,250);
              StateLabel7.setPosition(170-bwidth,300);
              StateLabel8.setPosition(370-bwidth,300);
              StateLabel9.setPosition(170-bwidth,350);
              StateLabel10.setPosition(370-bwidth,350);
              StateLabel11.setPosition(170-bwidth,400);
              StateLabel12.setPosition(370-bwidth,400);

              window.draw(Box1);
              window.draw(Box2);
              window.draw(Box3);
              window.draw(Box4);
              window.draw(Box5);
              window.draw(Box6);
              window.draw(Box7);
              window.draw(Box8);
              window.draw(Box9);
              window.draw(Box10);
              window.draw(Box11);
              window.draw(Box12);


              window.draw(StateLabel1);
              window.draw(StateLabel2);
              window.draw(StateLabel3);
              window.draw(StateLabel4);
              window.draw(StateLabel5);
              window.draw(StateLabel6);
              window.draw(StateLabel7);
              window.draw(StateLabel8);
              window.draw(StateLabel9);
              window.draw(StateLabel10);
              window.draw(StateLabel11);
              window.draw(StateLabel12);

              window.display();

              while(window.isOpen())
              {
                while (window.pollEvent(event)) 
                {

                  if (event.type == sf::Event::Closed) //function for close needed
                  {
                    window.close();
                  }

                  if (event.type == sf::Event::MouseButtonPressed) 
                  {
                    if (isMouseOver(window, home)) 
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_home++;
                        break;
                      }
                    }

                    //Now we check for each Box available

                    if(isMouseOver(window, Box1))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State1++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box2))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State2++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box3))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State3++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box4))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State4++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box5))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State5++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box6))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State6++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box7))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State7++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box8))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State8++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box9))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State9++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box10))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State10++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box11))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State11++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box12))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State12++;
                        break;
                      }
                    }
                  }
                }

                if (count_home > 0) //Implement this in a function
                {
                  window.clear(sf::Color(137, 197, 125));
                  break;
                }

                if (count_State1 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_SouthEast.at(0));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state1 statement

                if (count_State2 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_SouthEast.at(1));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state2 statement

                if (count_State3 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_SouthEast.at(2));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state3 statement

                if (count_State4 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_SouthEast.at(3));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state4 statement

                if (count_State5 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_SouthEast.at(4));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state5 statement
                if (count_State6 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_SouthEast.at(5));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state6 statement

                if (count_State7 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_SouthEast.at(6));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state7 statement

                if (count_State8 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(2),Check_Y.at(2));
                  State.setString(Region_SouthEast.at(7));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state8 statement

                if (count_State9 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_SouthEast.at(8));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state9 statement 

                if (count_State10> 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_SouthEast.at(9));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state10 statement

                if (count_State11 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_SouthEast.at(10));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state11 statement   

                if (count_State12 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_SouthEast.at(11));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state12 statement 

                //To here   

                }

              } //end of the if count four

//SOUTHEAST ENDS HERE
//NORTHEAST STARTS HERE

            if (count_NorthEast > 0)
            {
              window.clear(sf::Color(137, 197, 125));
              Region.setString(Regions.at(4));
              window.draw(home);
              window.draw(Region);
              window.draw(homelabel);
              window.draw(Selection);
              window.draw(Ask_State);
              window.display();

              //Set Each State's String

              StateLabel1.setString(Region_NorthEast.at(0));
              StateLabel2.setString(Region_NorthEast.at(1));
              StateLabel3.setString(Region_NorthEast.at(2));
              StateLabel4.setString(Region_NorthEast.at(3));
              StateLabel5.setString(Region_NorthEast.at(4));
              StateLabel6.setString(Region_NorthEast.at(5));
              StateLabel7.setString(Region_NorthEast.at(6));
              StateLabel8.setString(Region_NorthEast.at(7));
              StateLabel9.setString(Region_NorthEast.at(8));
              StateLabel10.setString(Region_NorthEast.at(9));
              StateLabel11.setString(Region_NorthEast.at(10));

              // Draw Each Box and button for West
              Box1.setPosition(170,150);
              Box2.setPosition(370,150);
              Box3.setPosition(170,200);
              Box4.setPosition(370,200);
              Box5.setPosition(170,250);
              Box6.setPosition(370,250);
              Box7.setPosition(170,300);
              Box8.setPosition(370,300);
              Box9.setPosition(170,350);
              Box10.setPosition(370,350);
              Box11.setPosition(270,400);
              
              //Draw Each State
              StateLabel1.setPosition(170-bwidth,150);
              StateLabel2.setPosition(370-bwidth,150);
              StateLabel3.setPosition(170-bwidth,200);
              StateLabel4.setPosition(370-bwidth,200);
              StateLabel5.setPosition(170-bwidth,250);
              StateLabel6.setPosition(370-bwidth,250);
              StateLabel7.setPosition(170-bwidth,300);
              StateLabel8.setPosition(370-bwidth,300);
              StateLabel9.setPosition(170-bwidth,350);
              StateLabel10.setPosition(370-bwidth,350);
              StateLabel11.setPosition(270-bwidth,400);

              window.draw(Box1);
              window.draw(Box2);
              window.draw(Box3);
              window.draw(Box4);
              window.draw(Box5);
              window.draw(Box6);
              window.draw(Box7);
              window.draw(Box8);
              window.draw(Box9);
              window.draw(Box10);
              window.draw(Box11);


              window.draw(StateLabel1);
              window.draw(StateLabel2);
              window.draw(StateLabel3);
              window.draw(StateLabel4);
              window.draw(StateLabel5);
              window.draw(StateLabel6);
              window.draw(StateLabel7);
              window.draw(StateLabel8);
              window.draw(StateLabel9);
              window.draw(StateLabel10);
              window.draw(StateLabel11);

              //To here

              window.display();

              while(window.isOpen())
              {
                while (window.pollEvent(event)) 
                {

                  if (event.type == sf::Event::Closed) //function for close needed
                  {
                    window.close();
                  }

                  if (event.type == sf::Event::MouseButtonPressed) 
                  {
                    if (isMouseOver(window, home)) 
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_home++;
                        break;
                      }

                    }

                    //Now we check for each Box available

                    if(isMouseOver(window, Box1))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State1++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box2))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State2++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box3))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State3++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box4))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State4++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box5))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State5++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box6))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State6++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box7))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State7++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box8))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State8++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box9))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State9++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box10))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State10++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box11))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State11++;
                        break;
                      }
                    }

                    if(isMouseOver(window, Box12))
                    {
                      if (event.mouseButton.button == sf::Mouse::Left) 
                      {
                        count_State12++;
                        break;
                      }
                    }

                    //To here   
                  }

                }

                if (count_home > 0) //Implement this in a function
                {
                  window.clear(sf::Color(137, 197, 125));
                  break;
                }
                                                //Copy here

                if (count_State1 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_NorthEast.at(0));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state1 statement

                if (count_State2 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_NorthEast.at(1));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state2 statement

                if (count_State3 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_NorthEast.at(2));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state3 statement

                if (count_State4 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_NorthEast.at(3));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state4 statement

                if (count_State5 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_NorthEast.at(4));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state5 statement
                if (count_State6 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_NorthEast.at(5));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state6 statement

                if (count_State7 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_NorthEast.at(6));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state7 statement

                if (count_State8 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_NorthEast.at(7));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state8 statement

                if (count_State9 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(0),Check_Y.at(0));
                  State.setString(Region_NorthEast.at(8));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state9 statement 

                if (count_State10> 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_NorthEast.at(9));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state10 statement

                if (count_State11 > 0) 
                {
                  Check_Sprite.setPosition(Check_X.at(1),Check_Y.at(1));
                  State.setString(Region_NorthEast.at(10));
                  window.clear(sf::Color(137, 197, 125));
                  window.draw(State);
                  window.draw(home);
                  window.draw(homelabel);
                  window.draw(Selection);
                  window.draw(Category);
                  window.draw(Check_Sprite);
                  window.display();

                  while(window.isOpen())
                  {
                    while (window.pollEvent(event)) 
                    {

                      if (event.type == sf::Event::Closed) //function for close needed
                      {
                        window.close();
                      }

                      if (event.type == sf::Event::MouseButtonPressed) //Generate Mouse Clicks
                      {
                        if (isMouseOver(window, home)) 
                        {
                        if (event.mouseButton.button == sf::Mouse::Left) 
                          {
                          count_home++;
                          break;
                          }
                        }
                      }

                    }
                    if (count_home > 0) //Implement this in a function
                    {
                    window.clear(sf::Color(137, 197, 125));
                    break;
                    }
                  } //Window is open
              
                } // end of if state11 statement   

                //To here   

                }

              } //end of the if count five

//NORTHEAST ENDS HERE

            }

          }
        }
  
               else
             Legality.setFillColor(sf::Color::White);
      }

    }
  }

return 0;

}

int main() 
{
  Legal_Function();
}

