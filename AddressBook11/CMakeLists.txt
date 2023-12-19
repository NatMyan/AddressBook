cmake_minimum_required(VERSION 3.5)
project(AddressBookQtApp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(AddressBookQtApp
    "Data/DatabaseManager.cpp"
    "Data/TabNames.cpp"
    "Data/User.cpp"
    "GUI/AddDialog.cpp"
    "GUI/SearchDialog.cpp"
    "GUI/SearchResultDialog.cpp"
    "GUI/TableInterface.cpp"
    "GUI/StartMenu.cpp"
    "GUI/SignInMenu.cpp"
    "GUI/SignUpMenu.cpp"
    "Logic/SignInMenuLogic.cpp"
    "Logic/SignUpMenuLogic.cpp"
    "Logic/TableLogic.cpp"
    "GUI/MainWindow.cpp"
    "main.cpp"
)

target_link_libraries(AddressBookQtApp PRIVATE Qt6::Core Qt6::Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)
target_link_libraries(AddressBookQtApp PRIVATE Qt6::Sql)




