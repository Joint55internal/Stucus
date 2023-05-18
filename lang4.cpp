#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>
#include <random>

std::map<std::string, std::string> responses; // Map to store pre-written responses
std::vector<std::string> funFacts;

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
    responses["tell me a joke"] = "Sure, here's one: Why don't scientists trust atoms? Because they make up everything!";
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
    // Add fun facts
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
    } else {
        // If no pre-written response is found and it's not a known request, provide a generic response
        response = "I'm sorry, I don't have a response for that. You can try searching on Google.";
    }

    return response;
}

int main() {
    initializeResponses();

    std::string input;
    std::cout << logo;
    std::cout << "Welcome! How can I assist you? (Type 'q' to exit)\n";
    while (true) {
        std::cout << " > ";
        std::getline(std::cin, input);
        std::cout << "AI: " << getResponse(input) << std::endl;

        if (input == "q") {
            break;
        }
    }

    return 0;
}