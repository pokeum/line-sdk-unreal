#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, TableAction) {
    TableAction_SetupSDK,
    TableAction_Login,
    TableAction_GetProfile,
    TableAction_GetCurrentAccessToken,
    TableAction_Logout,
    TableAction_GetBotFriendshipStatus,
    TableAction_RefreshAccessToken,
    TableAction_RevokeAccessToken,
    TableAction_VerifyAccessToken,
    TableAction_Count // Keeps track of the total number of actions
};

@interface ViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>

@end
