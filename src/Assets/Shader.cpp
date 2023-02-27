#include "Inari/Assets/Shader.h"

#include <glad/glad.h>

namespace inari {
    Shader::Shader(const Data& data)
        : m_id(data.id)
    {
    }

    Shader::~Shader() { glDeleteProgram(m_id); }

    void Shader::use() const { glUseProgram(m_id); }

    void Shader::set(const std::string_view& name, int value) const
    {
        glUniform1i(glGetUniformLocation(m_id, name.data()), value);
    }

    void Shader::set(const std::string_view& name, bool value) const { set(name, static_cast<int>(value)); }

    void Shader::set(const std::string_view& name, float value) const
    {
        glUniform1f(glGetUniformLocation(m_id, name.data()), value);
    }

    void Shader::set(const std::string_view& name, const Vec2f& value) const
    {
        glUniform2f(glGetUniformLocation(m_id, name.data()), value.x, value.y);
    }

    void Shader::set(const std::string_view& name, const Vec3f& value) const
    {
        glUniform3f(glGetUniformLocation(m_id, name.data()), value.x, value.y, value.z);
    }

    void Shader::set(const std::string_view& name, const Vec4f& value) const
    {
        glUniform4f(glGetUniformLocation(m_id, name.data()), value.x, value.y, value.z, value.w);
    }

    void Shader::set(const std::string_view& name, const Color& value) const
    {
        const Color::Clamped color = value.getClampedColor();
        glUniform4f(glGetUniformLocation(m_id, name.data()), color.r, color.g, color.b, color.a);
    }

    void Shader::set(const std::string_view& name, const Mat4& matrix) const
    {
        glUniformMatrix4fv(glGetUniformLocation(m_id, name.data()), 1, false, matrix.data());
    }

    int32_t Shader::getAttributePosition(const std::string_view& name) const
    {
        return glGetAttribLocation(m_id, name.data());
    }
} // namespace inari
