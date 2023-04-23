#include "macros/build_macro.h"
#include "util/Headers.h"
#include "util/Global.h"

#include "util/Utils.h"
#include "util/namespaces/G.h"
#include "handlers/File.h"
#include "handlers/Input.h"
#include "util/namespaces/Input.h"
#include "core/window/Window.h"
#include "util/namespaces/MainWindow.h"
#include "core/window/MainWindowSpecs.h"
#include "core/buffer/Buffer.h"
#include "core/buffer/VertexBuffer.h"
#include "g_unit/Batch.h"
#include "g_unit/Controllable.h"
#include "g_unit/Renderer.h"
#include "core/window/MainWindow.h"
#include "g_unit/Primitive.h"
#include "g_unit/player/Player.h"
#include "core/MainLoop.h"
#include "core/Application.h"

int main() {
	
	Global::init();

	Application* app = Application::getInstance();
	
	return 0;
}