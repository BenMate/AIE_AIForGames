#pragma once
#include "GameObject.h"
#include "raylib.h"
#include <functional>
#include <string>

class Button : public GameObject
{
public:
    Button();
    Button(Vector2 position, Vector2 size, std::string text, int fontSize, Color color, Color hoverColor, Color fontColor);
    ~Button();

    void Update(float deltaTime);
    void Draw();

    void SetOnButtonClick(std::function<void(Button* sender)> onClickFunc);

    void SetOnButtonMouseEnter(std::function<void(Button* sender)> onMouseEnterFunc);

    void SetOnButtonMouseExit(std::function<void(Button* sender)> onMouseExitFunc);

    void UseButton();

    bool IsPointInRect(Vector2* point, Vector2 rectPos, Vector2 rectSize);


private:

    std::function<void(Button* sender)> onButtonEventFunc;
    std::function<void(Button* sender)> onMouseClickFunc;
    std::function<void(Button* sender)> onMouseEnterFunc;
    std::function<void(Button* sender)> onMouseExitFunc;

    bool m_isMouseOver = false;
    int m_fontSize = 14;

    Vector2 m_size = { 100, 25 };
    Vector2 m_textSize = { 0, 0 };
    Vector2* m_lastFrameMousePos = nullptr;

    std::string m_text = "Button Text";

    Color m_color = GRAY;
    Color m_hoverColor = DARKGRAY;
    Color m_fontColor = RAYWHITE;
};