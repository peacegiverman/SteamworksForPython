//===============================================
//  STEAMWORKS FOR PYTHON
//===============================================

// Modify SW_PY based on operating system and include the proper Steamworks API file
//-----------------------------------------------
#if defined( _WIN32 )
	#include "steam\steam_api.h"
	#define SW_PY extern "C" __declspec( dllexport )
#elif defined( __APPLE__ )
	#include "steam/steam_api.h"
	#include "TargetConditionals.h"
	#define SW_PY extern "C" __attribute__ ((visibility("default")))
#elif defined( __linux__ )
	#include "steam/steam_api.h"
	#define SW_PY extern "C" __attribute__ ((visibility("default")))
#else
	#error "Unsupported platform"
#endif

// Steamworks functions
//-----------------------------------------------
SW_PY bool SteamInit(void){
	return SteamAPI_Init();
}
SW_PY bool IsSteamRunning(void){
	return SteamAPI_IsSteamRunning();
}
// Steam Apps
SW_PY int GetDlcCount(){
	return SteamApps()->GetDLCCount();
}
SW_PY bool IsDlcInstalled(int32 value){
	return SteamApps()->BIsDlcInstalled(value);
}
SW_PY void RequestAppProofOfPurchaseKey(int32 value){
	return SteamApps()->RequestAppProofOfPurchaseKey(value);
}
// Steam Friends
SW_PY int GetFriendCount(int flag){
	return SteamFriends()->GetFriendCount(flag);
}
SW_PY const char* GetPersonaName(){
	return SteamFriends()->GetPersonaName();
}
SW_PY int GetPersonaState(){
	return SteamFriends()->GetPersonaState();
}
SW_PY void ActivateGameOverlay(const char* name){
	return SteamFriends()->ActivateGameOverlay(name);	
}
// Steam Music
SW_PY bool MusicIsEnabled(){
	return SteamMusic()->BIsEnabled();
}
SW_PY bool MusicIsPlaying(){
	return SteamMusic()->BIsPlaying();
}
SW_PY float MusicGetVolume(){
	return SteamMusic()->GetVolume();
}
SW_PY void MusicPause(){
	return SteamMusic()->Pause();
}
SW_PY void MusicPlay(){
	return SteamMusic()->Play();
}
SW_PY void MusicPlayNext(){
	return SteamMusic()->PlayNext();
}
SW_PY void MusicPlayPrev(){
	return SteamMusic()->PlayPrevious();
}
SW_PY void MusicSetVolume(float value){
	return SteamMusic()->SetVolume(value);
}
// Steam User
SW_PY CSteamID GetSteamID(){
	return SteamUser()->GetSteamID();
}
SW_PY int GetPlayerSteamLevel(){
	return SteamUser()->GetPlayerSteamLevel(); 
}
// Steam User Stats
SW_PY bool ClearAchievement(const char* name){
	return SteamUserStats()->ClearAchievement(name);
}
SW_PY bool GetAchievement(const char* name){
	bool achieved = false;
	SteamUserStats()->GetAchievement(name, &achieved);
	return achieved;
}
SW_PY float GetStatFloat(const char* name){
	float statval = 0;
	SteamUserStats()->GetStat(name, &statval);
	return statval;
}
SW_PY int32 GetStatInt(const char* name){
	int32 statval = 0;
	SteamUserStats()->GetStat(name, &statval);
	return statval;
}
SW_PY bool ResetAllStats(bool achievesToo){
	return SteamUserStats()->ResetAllStats(achievesToo);
}
SW_PY bool RequestCurrentStats(){
	return SteamUserStats()->RequestCurrentStats();
}
SW_PY bool SetAchievement(const char* name){
	return SteamUserStats()->SetAchievement(name);
}
SW_PY bool SetStatFloat(const char* name, float value){
	return SteamUserStats()->SetStat(name, value);
}
SW_PY bool SetStatInt(const char* name, int32 value){
	return SteamUserStats()->SetStat(name, value);
}
SW_PY bool StoreStats(){
	return SteamUserStats()->StoreStats();
}
// Steam Utilities
SW_PY uint8 GetCurrentBatteryPower(){
	return SteamUtils()->GetCurrentBatteryPower();
}
SW_PY const char* GetIPCountry(){
	return SteamUtils()->GetIPCountry();
}
SW_PY uint32 GetSecondsSinceAppActive(){
	return SteamUtils()->GetSecondsSinceAppActive();
}
SW_PY uint32 GetSecondsSinceComputerActive(){
	return SteamUtils()->GetSecondsSinceComputerActive();
}
SW_PY uint32 GetServerRealTime(){
	return SteamUtils()->GetServerRealTime();
}
SW_PY bool IsOverlayEnabled(){
	return SteamUtils()->IsOverlayEnabled();
}
SW_PY bool IsSteamRunningInVR(){
	return SteamUtils()->IsSteamRunningInVR();
}
SW_PY const char* GetSteamUILanguage(){
	return SteamUtils()->GetSteamUILanguage();
}
SW_PY uint32 GetAppID(){
	return SteamUtils()->GetAppID();
}