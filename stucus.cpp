#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>
#include <random>
#include <unordered_map>

std::map<std::string, std::string> responses; // Map to store pre-written responses
std::vector<std::string> funFacts;
std::vector<std::string> jokes;
std::unordered_map<std::string, std::string> capitals;

const std::string logo =
"███████╗████████╗██╗   ██╗ ██████╗██╗   ██╗███████╗\n"
"██╔════╝╚══██╔══╝██║   ██║██╔════╝██║   ██║██╔════╝\n"
"███████╗   ██║   ██║   ██║██║     ██║   ██║███████╗\n"
"╚════██║   ██║   ██║   ██║██║     ██║   ██║╚════██║\n"
"███████║   ██║   ╚██████╔╝╚██████╗╚██████╔╝███████║\n"
"╚══════╝   ╚═╝    ╚═════╝  ╚═════╝ ╚═════╝ ╚══════╝\n";

void initializeResponses() {
    // Load pre-written responses from a file or define them manually
    responses["hello"] = "Hi there! How can I help you?";
    responses["hello!"] = "Hi there! How can I help you?";
    responses["how are you"] = "I'm doing well, thank you!";
    responses["how are you?"] = "I'm doing well, thank you!";
    responses["how are you!"] = "I'm doing well, thank you!";
    responses["you are beautiful"] = "That's nice of you! Thank you!";
    responses["sing a song"] = "Sorry, that's beyond my ability";
    responses["pi"] = "3.1415926535...";
    responses["who are you"] = "I am your personal Assistant";
    responses["what's the weather today"] = "I'm sorry, I don't have access to real-time weather information.";
    responses["how old are you"] = "I don't have an age. I'm a virtual assistant.";
    responses["what's your favorite color"] = "I don't have the ability to see colors, but I'm happy to assist you!";
    responses["where are you from"] = "I exist in the digital realm and don't have a physical location.";
    responses["do you have any siblings"] = "As an AI, I don't have a family or siblings.";
    responses["what's the meaning of life"] = "The meaning of life can be subjective and varies for each individual.";
    // Add responses

    // Fun facts
    funFacts.push_back("Did you know that a cat's nose print is unique, much like a human's fingerprint?");
    funFacts.push_back("Here's a fun fact: Honey never spoils! Archaeologists have found pots of honey in ancient Egyptian tombs that are over 3,000 years old and still perfectly edible!");
    funFacts.push_back("Here's an interesting fact: The world's oldest known customer complaint is from ancient Babylon, dating back to around 1750 BCE!");
    funFacts.push_back("Did you know that the average person walks the equivalent of three times around the world in their lifetime?");
    funFacts.push_back("The shortest war in history was between Britain and Zanzibar in 1896, lasting only 38 minutes.");
    funFacts.push_back("Astronauts cannot cry in space because there is no gravity to pull tears down their cheeks.");
    funFacts.push_back("The world's oldest known recipe is for beer and dates back over 4,000 years to ancient Sumeria.");
    funFacts.push_back("The average person produces enough saliva in their lifetime to fill two swimming pools.");
    funFacts.push_back("Scotland has 421 words for 'snow' in its vocabulary, reflecting its rich variety of snowy conditions.");
    funFacts.push_back("Octopuses have three hearts: one for pumping blood to their organs and two for pumping blood to their gills.");
    funFacts.push_back("The Hawaiian alphabet only has 12 letters: A, E, I, O, U, H, K, L, M, N, P, and W.");
    funFacts.push_back("The first recorded use of the hashtag symbol (#) was in ancient Rome to represent the weight measurement 'pound.'");
    funFacts.push_back("The world's oldest known musical instrument is a flute made from a vulture's wing bone and is over 40,000 years old.");
    funFacts.push_back("Did you know that the fingerprints of a koala are so similar to humans that they can sometimes be confused at a crime scene?");
    funFacts.push_back("Here's a fun fact: The longest recorded flight of a chicken is 13 seconds!");
    funFacts.push_back("Here's an interesting fact: The world's largest snowflake was recorded in 1887 in Montana and measured 15 inches in diameter!");
    funFacts.push_back("Did you know that a group of flamingos is called a 'flamboyance'?");
    funFacts.push_back("The Great Wall of China is so long that it can be seen from space, contrary to the popular myth.");
    funFacts.push_back("Here's a surprising fact: Cows have best friends and can become stressed when separated from them!");
    funFacts.push_back("Did you know that the world's smallest mammal is the bumblebee bat, which weighs less than a penny?");
    funFacts.push_back("Here's an amazing fact: The Eiffel Tower can actually grow in height by up to 6 inches during the summer due to thermal expansion!");
    funFacts.push_back("Here's a fun fact: The longest recorded flight of a paper airplane is 27.9 seconds!");
    funFacts.push_back("Did you know that honeybees have to visit around two million flowers to produce just one pound of honey?");
    funFacts.push_back("Here's an interesting fact: The world's largest known living organism is a giant sequoia tree named 'General Sherman.'");
    funFacts.push_back("The average person blinks around 20 times per minute, which amounts to approximately 1,200 blinks per hour.");
    funFacts.push_back("Did you know that a group of pugs is called a 'grumble'?");

    // Add more fun facts
    //Jokes
    jokes.push_back("Sure, here's one: Why don't scientists trust atoms? Because they make up everything!");
    jokes.push_back("Sure, here's one: Why don't scientists trust atoms? Because they make up everything!");
    jokes.push_back("Why don't skeletons fight each other? They don't have the guts!");
    jokes.push_back("Why did the scarecrow win an award? Because he was outstanding in his field!");
    jokes.push_back("Why did the bicycle fall over? Because it was two-tired!");
    jokes.push_back("What do you call a fish wearing a crown? King mackerel!");
    jokes.push_back("Why did the tomato turn red? Because it saw the salad dressing!");
    jokes.push_back("What do you call a snowman with a six-pack? An abdominal snowman!");
    jokes.push_back("Why did the math book look sad? Because it had too many problems!");
    jokes.push_back("Why don't scientists trust atoms anymore? Because they make up everything!");
    jokes.push_back("Why don't skeletons fight each other? They don't have the guts!");
    // Add more Jokes
    // capitals and countries
    capitals["afghanistan"] = "kabul";
    capitals["albania"] = "tirana";
    capitals["algeria"] = "algiers";
    capitals["andorra"] = "andorra la vella";
    capitals["angola"] = "luanda";
    capitals["antigua and barbuda"] = "saint john's";
    capitals["armenia"] = "yerevan";
    capitals["australia"] = "canberra";
    capitals["austria"] = "vienna";
    capitals["azerbaijan"] = "baku";
    capitals["bahamas"] = "nassau";
    capitals["bahrain"] = "manama";
    capitals["bangladesh"] = "dhaka";
    capitals["barbados"] = "bridgetown";
    capitals["belarus"] = "minsk";
    capitals["belgium"] = "brussels";
    capitals["belize"] = "belmopan";
    capitals["benin"] = "porto-novo";
    capitals["bhutan"] = "thimphu";
    capitals["bolivia"] = "sucre";
    capitals["bosnia and herzegovina"] = "sarajevo";
    capitals["botswana"] = "gaborone";
    capitals["brazil"] = "brasília";
    capitals["brunei"] = "bandar seri begawan";
    capitals["bulgaria"] = "sofia";
    capitals["burkina faso"] = "ouagadougou";
    capitals["burundi"] = "gitega";
    capitals["cambodia"] = "phnom penh";
    capitals["cameroon"] = "yaoundé";
    capitals["canada"] = "ottawa";
    capitals["cape verde"] = "praia";
    capitals["central african republic"] = "bangui";
    capitals["chad"] = "ndjamena";
    capitals["chile"] = "santiago";
    capitals["china"] = "beijing";
    capitals["colombia"] = "bogotá";
    capitals["comoros"] = "moroni";
    capitals["congo (brazzaville)"] = "brazzaville";
    capitals["congo (kinshasa)"] = "kinshasa";
    capitals["costa rica"] = "san josé";
    capitals["croatia"] = "zagreb";
    capitals["cuba"] = "havana";
    capitals["cyprus"] = "nicosia";
    capitals["czech republic"] = "prague";
    capitals["denmark"] = "copenhagen";
    capitals["djibouti"] = "djibouti";
    capitals["dominica"] = "roseau";
    capitals["dominican republic"] = "santo domingo";
    capitals["east timor"] = "dili";
    capitals["ecuador"] = "quito";
    capitals["el salvador"] = "san salvador";
    capitals["equatorial guinea"] = "malabo";
    capitals["eritrea"] = "asmara";
    capitals["estonia"] = "tallinn";
    capitals["eswatini"] = "mbabane";
    capitals["ethiopia"] = "addis ababa";
    capitals["fiji"] = "suva";
    capitals["finland"] = "helsinki";
    capitals["gabon"] = "libreville";
    capitals["gambia"] = "banjul";
    capitals["georgia"] = "tbilisi";
    capitals["germany"] = "berlin"; 
    capitals["ghana"] = "accra";
    capitals["greece"] = "athens";
    capitals["grenada"] = "saint george's";
    capitals["guatemala"] = "guatemala city";
    capitals["guinea"] = "conakry";
    capitals["guinea-bissau"] = "bissau";
    capitals["guyana"] = "georgetown";
    capitals["haiti"] = "port-au-prince"; 
    capitals["honduras"] = "tegucigalpa";
    capitals["hungary"] = "budapest";
    capitals["iceland"] = "reykjavík";
    capitals["india"] = "new delhi";
    capitals["iran"] = "tehran";
    capitals["iraq"] = "baghdad";
    capitals["ireland"] = "dublin";
    capitals["israel"] = "jerusalem";
    capitals["ivory coast"] = "abidjan";
    capitals["jamaica"] = "kingston";
    capitals["japan"] = "tokyo";
    capitals["jordan"] = "amman";
    capitals["kazakhstan"] = "nur-sultan";
    capitals["kiribati"] = "tarawa";
    capitals["kosovo"] = "pristina";
    capitals["kuwait"] = "kuwait city";
    capitals["kyrgyzstan"] = "bishkek";
    capitals["laos"] = "vientiane";
    capitals["latvia"] = "riga";
    capitals["lebanon"] = "beirut";
    capitals["lesotho"] = "maseru";
    capitals["liberia"] = "monrovia";
    capitals["libya"] = "tripoli";
    capitals["liechtenstein"] = "vaduz";
    capitals["lithuania"] = "vilnius";
    capitals["luxembourg"] = "luxembourg city";
    capitals["madagascar"] = "antananarivo";
    capitals["malawi"] = "lilongwe";
    capitals["malaysia"] = "kuala lumpur";
    capitals["maldives"] = "male";
    capitals["mali"] = "bamako";
    capitals["malta"] = "valletta";
    capitals["marshall islands"] = "majuro";
    capitals["mauritania"] = "nouakchott";
    capitals["mauritius"] = "port louis";
    capitals["micronesia"] = "palikir";
    capitals["moldova"] = "chisinau";
    capitals["monaco"] = "monaco";
    capitals["mongolia"] = "ulaanbaatar";
    capitals["montenegro"] = "podgorica";
    capitals["morocco"] = "rabat";
    capitals["mozambique"] = "maputo";
    capitals["myanmar"] = "naypyidaw";
    capitals["namibia"] = "windhoek";
    capitals["nauru"] = "yaren";
    capitals["nepal"] = "kathmandu";
    capitals["nicaragua"] = "managua";
    capitals["niger"] = "niamey";
    capitals["north korea"] = "pyongyang";
    capitals["north macedonia"] = "skopje"; 
    capitals["norway"] = "oslo";
    capitals["oman"] = "muscat";
    capitals["pakistan"] = "islamabad";
    capitals["palau"] = "ngerulmud";
    capitals["panama"] = "panama city";
    capitals["papua new guinea"] = "port moresby";
    capitals["paraguay"] = "asunción";
    capitals["peru"] = "lima";
    capitals["philippines"] = "manila";
    capitals["poland"] = "warsaw";
    capitals["portugal"] = "lisbon";
    capitals["qatar"] = "doha";
    capitals["romania"] = "bucharest";
    capitals["russia"] = "moscow";
    capitals["rwanda"] = "kigali";
    capitals["saint kitts and nevis"] = "basseterre";
    capitals["saint lucia"] = "castries";
    capitals["saint vincent and the grenadines"] = "kingstown";
    capitals["samoa"] = "apia";
    capitals["san marino"] = "san marino";
    capitals["sao tome and principe"] = "são tomé";
    capitals["saudi arabia"] = "riyadh";
    capitals["senegal"] = "dakar"; 
    capitals["serbia"] = "belgrade";
    capitals["seychelles"] = "victoria";
    capitals["sierra leone"] = "freetown";
    capitals["singapore"] = "singapore";
    capitals["slovakia"] = "bratislava";
    capitals["slovenia"] = "ljubljana";
    capitals["solomon islands"] = "honiara"; 
    capitals["somalia"] = "mogadishu";
    capitals["south africa"] = "pretoria";
    capitals["south korea"] = "seoul";
    capitals["south sudan"] = "juba";
    capitals["spain"] = "madrid";
    capitals["sri lanka"] = "colombo";
    capitals["sudan"] = "khartoum";
    capitals["suriname"] = "paramaribo";
    capitals["sweden"] = "stockholm";
    capitals["switzerland"] = "bern";
    capitals["syria"] = "damascus";
    capitals["taiwan"] = "taipei";
    capitals["tajikistan"] = "dushanbe";
    capitals["tanzania"] = "dodoma";
    capitals["thailand"] = "bangkok";
    capitals["togo"] = "lomé";
    capitals["tonga"] = "nuku'alofa";
    capitals["trinidad and tobago"] = "port of spain";
    capitals["tunisia"] = "tunis";
    capitals["turkey"] = "ankara";
    capitals["turkmenistan"] = "ashgabat";
    capitals["tuvalu"] = "funafuti";
    capitals["uganda"] = "kampala";
    capitals["ukraine"] = "kyiv";
    capitals["united arab emirates"] = "abu dhabi";
    capitals["united kingdom"] = "london";
    capitals["united states"] = "washington D.C";
    capitals["uruguay"] = "montevideo";
    capitals["uzbekistan"] = "tashkent";
    capitals["vanuatu"] = "port vila";
    capitals["vatican city"] = "vatican city";
    capitals["venezuela"] = "caracas";
    capitals["vietnam"] = "hanoi";
    capitals["yemen"] = "sana'a";
    capitals["zambia"] = "lusaka";
    capitals["zimbabwe"] = "harare";
    
    // Add more country-capital pairs
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

std::string getGoogleSearchURL(const std::string& query) {
    // Create a Google search URL based on the query
    // You can customize the URL format based on your needs
    return "https://www.google.com/search?q=" + query;
}

bool isMathExpression(const std::string& input) {
    // Check if the input is a valid mathematical expression
    std::string validChars = "+-*/0123456789";
    return input.find_first_not_of(validChars) == std::string::npos;
}

std::string calculateExpression(const std::string& expression) {
    // Calculate the result of the mathematical expression
    std::stringstream ss(expression);
    double num1, num2;
    char op;
    ss >> num1 >> op >> num2;

    double result;
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                return "Error: Division by zero";
            }
            break;
        default:
            return "Error: Invalid operator";
    }

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << result;
    return oss.str();
}

std::string getRandomFunFact() {
    // Generate a random index to select a fun fact from the vector
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, funFacts.size() - 1);
    int index = dis(gen);

    return funFacts[index];
}
std::string getRandomjokes() {
    // Generate a random index to select a joke from the vector
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, jokes.size() - 1);
    int index = dis(gen);

    return jokes[index];
   
}
std::string getCapital(const std::string& country) {
    // Convert the input to lowercase for case-insensitive matching
    std::string lowercaseCountry = country;
    std::transform(lowercaseCountry.begin(), lowercaseCountry.end(), lowercaseCountry.begin(), ::tolower);

    // Check if the country exists in the capitals map
    auto it = capitals.find(lowercaseCountry);
    if (it != capitals.end()) {
        return it->second;
    }

    return "Unknown"; // Return "Unknown" if the capital is not found
}

std::string helpMessage = "Available commands examples:\n"
                          "- ctof (Celcius to Fahrenheit)\n"
                          "- froc (Fahrenheit to Celcius)\n"
                          "- tell me a Fun fact\n"
                          "- Tell me a joke\n"
                          "- cofc (shows country's capital\n"
                          "- help";

std::string getResponse(const std::string& input) {
    std::string response;

    // Convert the input to lowercase for case-insensitive matching
    std::string lowercaseInput = input;
    std::transform(lowercaseInput.begin(), lowercaseInput.end(), lowercaseInput.begin(), ::tolower);

    // Exclude "what is" from the input
    std::string trimmedInput;
    size_t startPos = lowercaseInput.find("what is");
    if (startPos != std::string::npos) {
        trimmedInput = lowercaseInput.substr(startPos + 8); // Length of "what is" is 8
        trimmedInput.erase(std::remove(trimmedInput.begin(), trimmedInput.end(), ' '), trimmedInput.end());
    } else {
        trimmedInput = lowercaseInput;
    }

    // Check if the modified input matches any pre-written response
    auto it = responses.find(trimmedInput);
    if (it != responses.end()) {
        response = it->second;
    } else if (isMathExpression(trimmedInput)) {
        // If the input is a valid mathematical expression, calculate the result
        response = calculateExpression(trimmedInput);
    } else if (trimmedInput == "convert f to c" || trimmedInput == "f to c" || trimmedInput == "fahrenheit to celsius") {
        double temperature;
        std::cout << "Enter the temperature in Fahrenheit: ";
        std::cin >> temperature;

        double convertedTemperature = fahrenheitToCelsius(temperature);
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << convertedTemperature;
        response = oss.str() + " °C";
    } else if (trimmedInput == "convert c to f" || trimmedInput == "c to f" || trimmedInput == "celsius to fahrenheit") {
        double temperature;
        std::cout << "Enter the temperature in Celsius: ";
        std::cin >> temperature;

        double convertedTemperature = celsiusToFahrenheit(temperature);
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << convertedTemperature;
        response = oss.str() + " °F";
    } else if (trimmedInput == "tell me a fun fact") {
        response = getRandomFunFact();
    } else if (trimmedInput == "tell me a joke") {
        response = getRandomjokes();    
    } else if (trimmedInput == "q") {
        response = "Goodbye!"; 
    } else if (trimmedInput == "cofc") {
        std::string country;
        std::cout << "Enter the name of the country: ";
        std::getline(std::cin, country);

        std::string capital = getCapital(country);
        if (capital != "Unknown") {
            response = "The capital of " + country + " is " + capital;
        } else {
            response = "I'm sorry, the capital of " + country + " is not in my database.";
        }
    } else if (input == "help") {
        std::cout << helpMessage << std::endl;    
    } else {
        // If no pre-written response is found and it's not a known request, provide a generic response
        std::string googleSearchURL = getGoogleSearchURL(trimmedInput); // Generated google search URL
        response = "I'm sorry, I don't have a response for that. You can try searching on Google at " +  googleSearchURL;
    }

    return response;
}

int main() {
    initializeResponses();

    std::string input;
    std::cout << logo;
    std::cout << "© 2023 Joint55internal\n";
    std::cout << "Please type 'help' to view command examples.\n";
    std::cout << "AI (^^): Welcome! How can I assist you? (Type 'q' to exit)\n";
    while (true) {
        std::cout << " > ";
        std::getline(std::cin, input);
        std::cout << "AI (^^): " << getResponse(input) << std::endl;

        if (input == "q") {
            break;
        }
    }

    return 0;
}
