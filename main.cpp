#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<std::string> Buff;

void CommandCall(const char* Name,const char* Command)
{
	std::system("cls");
	std::cout << "\n HalfPeopleSystemCacheCleaningTool";
	for (std::string &b :Buff)
	{
		std::cout << "\n" << b;
	}
	std::cout << "\n\n "<<Name;
	if (std::system(Command))
	{
		std::string B = Name;
		B.append(" : Cleanup successful.");
		Buff.push_back(B);
	}
	else
	{
		std::string B = Name;
		B.append(" : Cleanup failed.");
		Buff.push_back(B);
	}
}
int main()
{
	std::cout << "\n HalfPeopleSystemCacheCleaningTool";
	std::cout << "\n Starting ...\n";
	char* username = nullptr;
	size_t len = 0;
	errno_t err = _dupenv_s(&username, &len, "USERNAME");

	if (err == 0 && username != nullptr) {
		std::cout << "Username: " << username << std::endl;
		free(username);
	}
	else {
		std::cout << "Failed to get username!" << std::endl;
	}
	
	CommandCall("清理Temp文件夾", "del /s /q C:\\Temp\\*.*");
	CommandCall("清理Windows\\Temp文件夾", "del /s /q C:\\Windows\\Temp\\*.*");
	CommandCall("清理Prefetch文件夾 :", "del /q C:\\Windows\\Prefetch\\*.*");
	CommandCall("清空資源回收筒 :", "rd /s /q C:\\$Recycle.Bin");
	CommandCall("清理更新暫存文件夾 :", "del /s /q C:\\Windows\\SoftwareDistribution\\Download\\*.*");
	CommandCall("清理瀏覽器緩存 - Google Chrome :", std::string("rd /s /q \"C:\\Users\\").append(username).append("\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Cache\"").c_str());
	CommandCall("清理瀏覽器緩存 - Microsoft Edge :", std::string("rd /s /q \"C:\\Users\\").append(username).append("\\AppData\\Local\\Microsoft\\Edge\\User Data\\Default\\Cache\"").c_str());
	CommandCall("清理UE4引擎緩存文件 - EpicGamesLauncher:", std::string("rmdir /s /q \"C:\\Users\\").append(username).append("\\AppData\\Local\\EpicGamesLauncher\"").c_str());
	CommandCall("清理UE4引擎緩存文件 - UnrealEngine:", std::string("rmdir /s /q \"C:\\Users\\").append(username).append("\\AppData\\Local\\UnrealEngine\"").c_str());
	CommandCall("清理Unity引擎緩存文件 - Unity - LocalLow:", std::string("rmdir /s /q \"C:\\Users\\").append(username).append("\\AppData\\LocalLow\\Unity\"").c_str());
	CommandCall("清理Unity引擎緩存文件 - Unity - Roaming:", std::string("rmdir /s /q \"C:\\Users\\").append(username).append("\\AppData\\Roaming\\Unity\"").c_str());
	CommandCall("清理Steam遊戲的緩存文件:","call \"C:\\Program Files (x86)\\Steam\\steam.exe -flushconfig\"");
}
