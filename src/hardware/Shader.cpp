#include "hardware/Shader.hpp"

void Shader::compile()
{
    if(_id != 0)
        glDeleteProgram(_id);

    // Create the shaders
    GLuint vertShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file
    std::string vertShaderCode;
    std::ifstream vertShaderStream(_vsPath, std::ios::in);
    if(vertShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(vertShaderStream, Line))
            vertShaderCode += "\n" + Line;
        vertShaderStream.close();
    }

    // Read the Fragment Shader code from the file
    std::string fragShaderCode;
    std::ifstream fragShaderStream(_fsPath, std::ios::in);
    if(fragShaderStream.is_open()){
        std::string Line = "";
        while(getline(fragShaderStream, Line))
            fragShaderCode += "\n" + Line;
        fragShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int infoLogLen;

    printf("Compiling shader : %s\n", _vsPath);
    char const *vertSourcePointer = vertShaderCode.c_str();
    glShaderSource(vertShaderID, 1, &vertSourcePointer , NULL);
    glCompileShader(vertShaderID);

    // Check Vertex Shader
    glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(vertShaderID, GL_INFO_LOG_LENGTH, &infoLogLen);
    std::vector<char> vertShaderErrMsgs(infoLogLen);
    glGetShaderInfoLog(vertShaderID, infoLogLen, NULL, &vertShaderErrMsgs[0]);
    fprintf(stdout, "%s\n", &vertShaderErrMsgs[0]);

    // Compile Fragment Shader
    printf("Compiling shader : %s\n", _vsPath);
    char const *fragSourcePointer = fragShaderCode.c_str();
    glShaderSource(fragShaderID, 1, &fragSourcePointer , NULL);
    glCompileShader(fragShaderID);

    // Check Fragment Shader
    glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(fragShaderID, GL_INFO_LOG_LENGTH, &infoLogLen);
    std::vector<char> fragShaderErrMsgs(infoLogLen);
    glGetShaderInfoLog(fragShaderID, infoLogLen, NULL, &fragShaderErrMsgs[0]);
    fprintf(stdout, "%s\n", &fragShaderErrMsgs[0]);

    // Link the program
    fprintf(stdout, "Linking program\n");
    GLuint progID = glCreateProgram();
    glAttachShader(progID, vertShaderID);
    glAttachShader(progID, fragShaderID);
    glLinkProgram(progID);

    // Check the program
    glGetProgramiv(progID, GL_LINK_STATUS, &Result);
    glGetProgramiv(progID, GL_INFO_LOG_LENGTH, &infoLogLen);
    std::vector<char> progErrMsgs(std::max(infoLogLen, int(1)));
    glGetProgramInfoLog(progID, infoLogLen, NULL, &progErrMsgs[0]);
    fprintf(stdout, "%s\n", &progErrMsgs[0]);

    glDeleteShader(vertShaderID);
    glDeleteShader(fragShaderID);

    std::cout << "Compiled shader with ID #" << progID << std::endl;

    _id = progID;
}

void Shader::compile(const char *vertSourcePointer, const char *fragSourcePointer)
{
    if(_id != 0)
        glDeleteProgram(_id);

    // Create the shaders
    GLuint vertShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    GLint Result = GL_FALSE;
    int infoLogLen;

    glShaderSource(vertShaderID, 1, &vertSourcePointer , NULL);
    glCompileShader(vertShaderID);

    // Check Vertex Shader
    glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(vertShaderID, GL_INFO_LOG_LENGTH, &infoLogLen);
    std::vector<char> vertShaderErrMsgs(infoLogLen);
    glGetShaderInfoLog(vertShaderID, infoLogLen, NULL, &vertShaderErrMsgs[0]);

    // Compile Fragment Shader
    glShaderSource(fragShaderID, 1, &fragSourcePointer , NULL);
    glCompileShader(fragShaderID);

    // Check Fragment Shader
    glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(fragShaderID, GL_INFO_LOG_LENGTH, &infoLogLen);
    std::vector<char> fragShaderErrMsgs(infoLogLen);
    glGetShaderInfoLog(fragShaderID, infoLogLen, NULL, &fragShaderErrMsgs[0]);

    // Link the program
    fprintf(stdout, "Linking program\n");
    GLuint progID = glCreateProgram();
    glAttachShader(progID, vertShaderID);
    glAttachShader(progID, fragShaderID);
    glLinkProgram(progID);

    // Check the program
    glGetProgramiv(progID, GL_LINK_STATUS, &Result);
    glGetProgramiv(progID, GL_INFO_LOG_LENGTH, &infoLogLen);
    std::vector<char> progErrMsgs(std::max(infoLogLen, int(1)));
    glGetProgramInfoLog(progID, infoLogLen, NULL, &progErrMsgs[0]);
    fprintf(stdout, "%s\n", &progErrMsgs[0]);

    glDeleteShader(vertShaderID);
    glDeleteShader(fragShaderID);

    std::cout << "Compiled shader with ID #" << progID << std::endl;
    _id = progID;
}
