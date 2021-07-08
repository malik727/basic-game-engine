# The compiler to use
CXX = g++
# Enabling all warning errors and debugging
CXXFLAGS = -g3 -std=c++11 -Wall -fmessage-length=0 
# Specifying Object files
OBJS = main.o CompiledData/ErrorHandler.o CompiledData/MainEngine.o CompiledData/VertexBuffer.o CompiledData/IndexBuffer.o CompiledData/VertexArray.o CompiledData/VBSpecs.o CompiledData/Shader.o CompiledData/Texture.o CompiledData/EngineCamera.o CompiledData/OBJLoader.o CompiledData/STB_Image.o
# Specifying external libraries
LIBS = -lglfw -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -lGL -lGLEW -lpthread -ldl
# The final executable file
TARGET = runengine

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Compiling Dependencies
CompiledData/ErrorHandler.o: GameEngine/ErrorHandler.cpp GameEngine/ErrorHandler.h
	$(CXX) -c GameEngine/ErrorHandler.cpp -o CompiledData/ErrorHandler.o

CompiledData/MainEngine.o: GameEngine/MainEngine.cpp GameEngine/MainEngine.h
	$(CXX) -c GameEngine/MainEngine.cpp -o CompiledData/MainEngine.o

CompiledData/VertexBuffer.o: GameEngine/VertexBuffer.cpp GameEngine/VertexBuffer.h
	$(CXX) -c GameEngine/VertexBuffer.cpp -o CompiledData/VertexBuffer.o

CompiledData/IndexBuffer.o: GameEngine/IndexBuffer.cpp GameEngine/IndexBuffer.h
	$(CXX) -c GameEngine/IndexBuffer.cpp -o CompiledData/IndexBuffer.o

CompiledData/VertexArray.o: GameEngine/VertexArray.cpp GameEngine/VertexArray.h
	$(CXX) -c GameEngine/VertexArray.cpp -o CompiledData/VertexArray.o

CompiledData/VBSpecs.o: GameEngine/VBSpecs.cpp GameEngine/VBSpecs.h
	$(CXX) -c GameEngine/VBSpecs.cpp -o CompiledData/VBSpecs.o

CompiledData/Shader.o: GameEngine/Shader.cpp GameEngine/Shader.h
	$(CXX) -c GameEngine/Shader.cpp -o CompiledData/Shader.o

CompiledData/Texture.o: GameEngine/Texture.cpp GameEngine/Texture.h
	$(CXX) -c GameEngine/Texture.cpp -o CompiledData/Texture.o

CompiledData/EngineCamera.o: GameEngine/EngineCamera.cpp GameEngine/EngineCamera.h
	$(CXX) -c GameEngine/EngineCamera.cpp -o CompiledData/EngineCamera.o

CompiledData/OBJLoader.o: GameEngine/OBJLoader.cpp GameEngine/OBJLoader.h
	$(CXX) -c GameEngine/OBJLoader.cpp -o CompiledData/OBJLoader.o

CompiledData/STB_Image.o: GameEngine/vendor/STB_Image.cpp GameEngine/vendor/STB_Image.h
	$(CXX) -c GameEngine/vendor/STB_Image.cpp -o CompiledData/STB_Image.o

all: $(TARGET)

clean: rm -f $(OBJS) $(TARGET)