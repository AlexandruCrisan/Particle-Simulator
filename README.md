# Particle Simulator 💥  
![Django](https://img.shields.io/badge/Django-092E20?style=for-the-badge&logo=django&logoColor=green) ![Tailwdincss](https://img.shields.io/badge/tailwindcss-0F172A?&logo=tailwindcss)  ![SpotifyAPI](https://img.shields.io/badge/Spotify-1ED760?&style=for-the-badge&logo=spotify&logoColor=white) ![GoogleAPIs](https://img.shields.io/badge/Google_APIs-4285F4?style=for-the-badge&logo=google&logoColor=white) ![Youtube](https://img.shields.io/badge/Youtube-FF0000)

**Particle Simulator** is a captivating simulation that demonstrates how particles interact under a gravitational field. The project allows users to choose from a set of images —or even upload their own— where each pixel is treated as a particle. When the left mouse button is pressed, a gravitational field is created around the cursor, attracting and disintegrating the image in a visually satisfying way.


![error image](https://github.com/AlexandruCrisan/Particle-Simulator/blob/master/demo.gif?raw=true) 
---

## 🌟 Features

- 🎨 **Image Selection:** Choose from a predefined set of images or upload your own.
- 🖱 **Interactive Gravity:** Press the left mouse button to generate a gravitational field around the cursor.
- ⚡ **Dynamic Particle Simulation:** Each pixel (particle) is attracted to the gravitational source and destroyed in real time.
- 🔍 **Realistic Physics:** Watch the simulation in action as each particle's movement is computed based on gravitational force.

---

## 🛠️ Tech Stack
- ⚙️ **C++** – The core language used for high-performance simulation.
- 🎮 **SFML** – Used for rendering graphics and managing window events.
- 🖼 **OpenCV** – Employed for image processing tasks like resizing and manipulation.

---

## [🎬 Demo Video](https://youtu.be/-0faOvsaK6A)

Click the link above to watch a higher-resolution demo of this project!

---

## 📐 Math Behind the Simulation
The simulation is driven by a physics-based algorithm that computes the gravitational effect on every particle (pixel) in the image. The steps involved are:

```cpp
   // This is the distance in (x, y)
  sf::Vector2f distance = source.get_position() - this->position;

  // Normalize the distance (divide by the hypothenuse, using Pythagorean theorem)
  distance /= std::sqrt(distance.x * distance.x + distance.y * distance.y);

  sf::Vector2f acceleration = distance * source.get_power();

  this->velocity += acceleration;
```


1. **Calculate the Distance:**  
   - Determine the distance between the gravitational source (cursor) and each particle using the Pythagorean theorem.

2. **Normalize the Distance:**  
   - Normalize the x and y distances by dividing each by the calculated hypotenuse (distance).
   
  ![error image](https://github.com/AlexandruCrisan/Particle-Simulator/blob/master/mathb.PNG?raw=true) 

3. **Compute the Acceleration:**  
   - Multiply the normalized x and y distances by the power of the gravitational field to determine the acceleration vector.

4. **Update Velocity:**  
   - Add the acceleration vector to the current velocity of the particle.

5. **Iterate for All Particles:**  
   - Repeat the above steps for every particle on the screen, updating their positions and simulating the gravitational effect.

---

## 🚀 Getting Started

### **1️⃣ Clone the Repository**

```sh
 git clone https://github.com/AlexandruCrisan/Particle-Simulator.git
 cd Particle-Simulator
```

### **2️⃣ Build the Porject**
- Use your preferred build system / IDE. For example, if you're using CMake:

```sh
 mkdir build && cd build
 cmake ..
 make
```
- You can also open the project in Visual Studio and build/run it from the IDE.
- The SFML dependencies and sample images are already included in the `x64` Folder.

## 📜 License

This project is licensed under the MIT License.

---

> Made by [Crisan Alexandru](https://github.com/AlexandruCrisan)

