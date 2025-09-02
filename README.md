# MyToDo

A simple and intuitive Qt-based ToDo application for managing your daily tasks.

## Features

- **Add Tasks**: Easily add new tasks to your todo list
- **Edit Tasks**: Double-click on any task to edit or update it
- **Delete Tasks**: Remove completed or unwanted tasks
- **SQLite Database**: All data is stored locally using SQLite
- **User-friendly Interface**: Clean and simple GUI built with Qt
- **Cross-platform**: Runs on Linux, Windows, and macOS

## Requirements

- Qt 5 or Qt 6 (with Widgets and SQL modules)
- CMake 3.16 or higher
- C++17 compatible compiler
- SQLite (included with Qt)

## Building from Source

1. Clone the repository:
```bash
git clone <repository-url>
cd MyToDo
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Configure and build with CMake:
```bash
cmake ..
make
```

4. Run the application:
```bash
./MyToDo
```

## Usage

### Adding a Task
1. Type your task in the text field at the top
2. Click the "+ Add" button or press Enter
3. Your task will appear in the table below

### Editing/Deleting a Task
1. Click on any task in the table
2. An edit dialog will open
3. Choose to either:
   - **Update**: Modify the task text and click "Update"
   - **Delete**: Click "Delete" to remove the task

### Database Location
The application stores its database file at:
- Linux/macOS: `~/.config/database.db`
- The initial database template is copied from `/usr/share/doc/mytodo/database.db`

## File Structure

```
MyToDo/
├── CMakeLists.txt      # CMake build configuration
├── main.cpp            # Application entry point
├── mytodo.h/.cpp       # Main window class
├── mytodo.ui           # Main window UI design
├── edit.h/.cpp         # Edit dialog class
├── edit.ui             # Edit dialog UI design
├── assets.qrc          # Qt resource file
└── .gitignore          # Git ignore rules
```

## Database Schema

The application uses a simple SQLite table structure:

```sql
CREATE TABLE todos (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    todos TEXT NOT NULL,
    datetime DATETIME DEFAULT CURRENT_TIMESTAMP
);
```

## Contributing

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is open source. Please check the license file for more details.

## Author

**Caio S.**
- GitHub: [@sobreiracaio](https://github.com/sobreiracaio)

## Version

Current version: 1.0.0

---

*Built with Qt and ❤️*