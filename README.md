# Stucus

  
```md
███████╗████████╗██╗   ██╗ ██████╗██╗   ██╗███████╗
██╔════╝╚══██╔══╝██║   ██║██╔════╝██║   ██║██╔════╝
███████╗   ██║   ██║   ██║██║     ██║   ██║███████╗
╚════██║   ██║   ██║   ██║██║     ██║   ██║╚════██║
███████║   ██║   ╚██████╔╝╚██████╗╚██████╔╝███████║
╚══════╝   ╚═╝    ╚═════╝  ╚═════╝ ╚═════╝ ╚══════╝
```
    
    
<p align="center">
  <a href="#installation">Installation</a> •
  <a href="#usage">Usage</a> •
  <a href="#features">Features</a> •
  <a href="#customization">Customization</a> •
  <a href="#license">License</a>
</p> 

## Description
Stucus is a simple chatbot-like program

# Installation
1. Clone the repository:
```console
git clone https://github.com/Joint55internal/Stucus.git
```
2. Navigate to Stucus:
```console
cd Stucus
```
3. Compile the source code:
```console
g++ stucus.cpp -o stucus
```
# Usage
To use Stucus, execute the following command:
```console
./stucus
```
Interact with Stucus by typing your question or message.
Example conversaions:
```
> Hello
AI: Hi there! How can I help you?
> What's the weather today?
AI: I'm sorry, I don't have access to real-time weather information. You can try search on Google.
> Tell me a joke
AI: Sure, here's one: Why don't scientists trust atoms? Because they make up everything!
> Convert f to c
AI: Enter the temperature in Fahrenheit: 75
> 23.89 °C
> q
```
# Features

- Stucs can respond to pre-defined queries and provide appropriate answers.
- It can handle mathematical expressions and calculate the result.
- Conversion between Fahrenheit and Celsius temperatures is supported.
- Fun facts can be shared upon request.

# Customization

- Modify the initializeResponses() function to add or modify the pre-written responses.
- Update the funFacts vector with your own interesting facts.
- Customize the Stucs' behavior by extending the getResponse() function.

# License

- This project is licensed under the MIT Licence - See [LICENSE](/LICENSE) file for detail.
- Copyright © 2023 Joint55internal

