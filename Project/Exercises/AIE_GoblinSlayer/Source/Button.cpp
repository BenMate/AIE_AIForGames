
#include "Button.h"

Button::Button()
{
    m_textSize = MeasureTextEx(GetFontDefault(), m_text.c_str(), m_fontSize, 1.0f);
}

Button::~Button()
{

}

Button::Button(Vector2 position, Vector2 size, std::string text, int fontSize,
    Color color, Color hoverColor, Color fontColor)
{
    m_position = position;
    m_size = size;
    m_text = text;
    m_fontSize = fontSize;
    m_color = color;
    m_hoverColor = hoverColor;
    m_fontColor = fontColor;
    m_textSize = MeasureTextEx(GetFontDefault(), m_text.c_str(), fontSize, 1.0f);
}

void Button::Update(float deltaTime)
{
    Vector2 mousePos = GetMousePosition();
    m_isMouseOver = IsPointInRect(&mousePos, m_position, m_size);
    bool isMouseOverLastFrame = IsPointInRect(m_lastFrameMousePos, m_position, m_size);

    if (m_isMouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        UseButton();
    }

    if (m_isMouseOver && !isMouseOverLastFrame)
        onMouseEnterFunc(this);
    if (!m_isMouseOver && isMouseOverLastFrame)
        onMouseExitFunc(this);
    m_lastFrameMousePos = &mousePos;
}

bool Button::IsPointInRect(Vector2* point, Vector2 rectPos, Vector2 rectSize)
{
    if (point == nullptr)
        return false;

    return point->x >= rectPos.x &&
        point->x <= rectPos.x + rectSize.x &&
        point->y >= rectPos.y &&
        point->y <= rectPos.y + rectSize.y;
}

void Button::Draw()
{
    Color c = m_isMouseOver ? m_hoverColor : m_color;
    DrawRectangle(
        (int)(m_position.x), // TODO: Fix center align
        (int)(m_position.y),
        (int)m_size.x,
        (int)m_size.y,
        c);
    DrawText(m_text.c_str(), (int)(m_position.x + (m_size.x / 2) - (m_textSize.x / 2)),
        (int)(m_position.y + (m_size.y / 2) - (m_textSize.y / 2)), m_fontSize, m_fontColor);
}

void Button::SetOnButtonClick(std::function<void(Button* sender)> onClickFunc)
{
    onMouseClickFunc = onClickFunc;
}

void Button::SetOnButtonMouseEnter(std::function<void(Button* sender)> onMouseEnterFunc)
{
    onMouseEnterFunc = onMouseEnterFunc;
}

void Button::SetOnButtonMouseExit(std::function<void(Button* sender)> onMouseExitFunc)
{
    onMouseExitFunc = onMouseExitFunc;
}

void Button::UseButton()
{
    if (onMouseClickFunc)
        onMouseClickFunc(this);
}