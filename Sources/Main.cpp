﻿#include "SandboxHeader.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int nCmdShow)
{
    return MessageBox(nullptr, L"Hello, World!", L"Framework Sandbox", 0);
}
