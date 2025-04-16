# Dream Project

The **Dream** project is a personal task and character management system designed to help users track and manage their tasks as well as character stats in a structured, easy-to-use CLI environment.

## Project Overview

This project includes two main components:
1. **Task Management** – allows users to manage tasks, set priorities, mark them as completed, and display them in a user-friendly way in the CLI.
2. **Character Management** – tracks character stats such as level, proficiency, and progression, and displays the character's information in a visually appealing format.

### Key Features

- **Task Management**
  - Add, update, and delete tasks.
  - Organize tasks by priority (high, medium, low).
  - Mark tasks as completed and display the status in the terminal.
  
- **Character Management**
  - Create and manage characters.
  - Track character levels and proficiency.
  - Display character stats with a custom ASCII avatar.

## Folder Structure

The project has the following folder structure:

```bash
├── CMakeLists.txt
├── lib
│   └── CMakeLists.txt
├── LICENSE
├── README.md
└── src
    ├── CMakeLists.txt
    ├── core
    │   ├── character-management
    │   │   ├── character-database.cpp
    │   │   ├── character-display-CLI.cpp
    │   │   ├── character-kernel.cpp
    │   │   ├── character-level.cpp
    │   │   └── include
    │   │       ├── character-database.h
    │   │       ├── character-display-CLI.h
    │   │       ├── character.h
    │   │       └── character-level.h
    │   └── task-management
    │       ├── include
    │       │   ├── task-creation.h
    │       │   ├── task-database.h
    │       │   ├── task-display-CLI.h
    │       │   └── task.h
    │       ├── task-creation.cpp
    │       ├── task-database.cpp
    │       ├── task-display-CLI.cpp
    │       └── task-kernel.cpp
    └── main.cpp
```


## Future Improvements

The project is still under development and is not fully operational. The main focus is on enhancing and refining the code to make it more efficient and stable. Some features are still in the process of being optimized.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
