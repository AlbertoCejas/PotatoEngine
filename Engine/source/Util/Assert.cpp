#include <PotatoEngine/Util/Assert.h>

#include <cstdio>
#include <cstdarg>
#include <cassert>

namespace potato
{
	void defaultHandler(const char* condition, const char* msg, const char* file, const int line)
	{
		printf("%s(%d): Assert Failure: ", file, line);

		if (condition != nullptr)
			printf("'%s' ", condition);

		if (msg != nullptr)
			printf("%s", msg);

		printf("\n");

		// TODO: __debugbreak();
		assert(false);
	}

	AssertHandler& getAssertHandlerInstance()
	{
		static AssertHandler handler = &defaultHandler;
		return handler;
	}

	void setHandler(AssertHandler assertHandler)
	{
		POTATO_ASSERT_MSG(assertHandler != nullptr, "Assert handler is nullptr");
		getAssertHandlerInstance() = assertHandler;
	}

	void reportFailure(const char* condition, const char* file, int line, const char* msg, ...)
	{
		const char* message = nullptr;
		if (msg != nullptr)
		{
			char messageBuffer[1024];
			{
				va_list args;
				va_start(args, msg);
				vsnprintf(messageBuffer, 1024, msg, args);
				va_end(args);
			}

			message = messageBuffer;
		}

		getAssertHandlerInstance()(condition, message, file, line);
	}
}