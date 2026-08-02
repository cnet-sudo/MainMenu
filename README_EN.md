# SFML Game Main Menu

[Русский](README.md) | **English**

![C++](https://img.shields.io/badge/C%2B%2B-14-00599C?logo=cplusplus)
![SFML](https://img.shields.io/badge/SFML-2.6.x-8CC445)

An educational full-screen game menu built with SFML. The project demonstrates
keyboard navigation, active-item highlighting, separate screens, background
images, music, and interface sounds.

## Features

- Play, Settings, About, and Exit entries;
- cyclic menu navigation;
- separate colors for normal and selected text;
- audio feedback while navigating;
- different music for the main and game screens;
- demonstration game, settings, and information screens;
- helper classes for asset loading and frame-based animation.

## Controls

- **Up / Down** — select an entry;
- **Enter** — open the selected section;
- **Esc** — return from a child screen.

## Main Files

| File | Purpose |
|---|---|
| `main.cpp` | menu states and demonstration screens |
| `GameMenu.*` | entries, highlighting, and navigation |
| `AssetManager.*` | texture, font, and sound loading |
| `Animator.*` | reusable frame-based animation |
| `image` | backgrounds and graphics |
| `font` | menu font |
| `audio` | music and interface sounds |

## Building with CMake

CMake 3.21+, Git, and a C++14 compiler are required. SFML 2.6.x is downloaded
during the first configuration.

```powershell
cmake -S . -B build -DBUILD_SHARED_LIBS=OFF
cmake --build build --config Release
./build/Release/GameMenu.exe
```

Assets from `audio`, `font`, and `image` are copied next to the executable.

When using `MainMenu.sln`, update the old absolute SFML 2.5.1 paths in the
project properties if your library is installed elsewhere.

## Reusing the Menu in Your Own Game

Instead of creating separate windows in `Game`, `Options`, and `About_Game`,
you can switch a single application state. `GameMenu` already receives a
window and a list of strings, which makes the class easy to reuse.

## Status

Complete educational UI example. It is not a standalone game: the Play entry
opens a demonstration screen.
