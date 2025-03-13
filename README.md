# QtQmlControllerExample
Decouple QML UI from business logic

What is the problem to solve?

Sometimes we can find these kind of structures in QML code:

```
var selectedVehicles = QGroundControl.multiVehicleManager.multiVehicleController.vehicles

```

We see here, that the QML UI has detailed knowledge about the backend.
Ideally, the UI is nicely decoupled and is blissfully unaware of the business logic.

The following Design proposal tries to tackle this:

1. There is one C++ class that is the “owner“ of the QML file (Controller in the example below).
2. The QML communicates TO the C++ file by emitting signals (see “onClicked: buttonPressed()“ in the example code)
3. Ideally the QML would know nothing about the backend, for example the C++ owner class. We will allow this in the case of communicating FROM C++ TO QML, to take advantage of Q_PROPERTY: 
In QML, this ensures that any bound UI elements or dependent logic are updated immediately and efficiently without additional boilerplate. See Q_PROPERTY example and the line text: controller.message  // Bind the text to the C++ message property in the example below.

In practice, objects are ideally divided into two classes:

1. A class that contains logic, such as state machines and interactions with the backend.
2. A class that serves as a data container, holding properties for the object's state.

This separation of concerns helps ensure a clean architecture. The data class exposes its state to the QML UI using Q_PROPERTY, allowing direct interaction. 
However, the UI should not be allowed to communicate directly with the logic class to maintain encapsulation and prevent unintended side effects.

# Prerequisites

### 📌 Requirements
- **Qt 6.5 or later** (Ensure it is installed and accessible)
- C++ compiler (such as `g++`)
- CMake (if using a CMake-based project)

---

## 🔧 Installing Qt on Ubuntu

### **Option 1: Using the Qt Online Installer (Latest Version)**
This method provides the **latest** Qt version and extra tools like Qt Creator.

1️⃣ **Download the Qt Online Installer**  
   - Go to [Qt Downloads](https://www.qt.io/download-open-source)  
   - Click **"Download the Qt Online Installer"**  
   - Choose the **Linux** version (`.run` file)

2️⃣ **Make the installer executable**  
   ```
   chmod +x qt-unified-linux-x64-online.run
   ```

3️⃣ Run the installer
```
./qt-unified-linux-x64-online.run
```

# How to build

```
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH="<path-to-Qt>/gcc_64/lib/cmake"
cmake --build .

```

# How to run

```
cd build
./QtQmlControllerExample

```


