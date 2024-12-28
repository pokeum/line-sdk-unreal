#import "ViewController.h"

#import <LineSDKWrapper/LineSDKWrapper.h>

@interface ViewController ()

@end

@implementation ViewController

- (NSString *)labelForAction:(TableAction)action {
    switch (action) {
    case TableAction_SetupSDK:
        return @"Setup SDK";
    case TableAction_Login:
        return @"Login";
    case TableAction_GetProfile:
        return @"Get Profile";
    case TableAction_GetCurrentAccessToken:
        return @"Get Current Access Token";
    case TableAction_Logout:
        return @"Logout";
    case TableAction_GetBotFriendshipStatus:
        return @"Get Bot Friendship Status";
    case TableAction_RefreshAccessToken:
        return @"Refresh Access Token";
    case TableAction_RevokeAccessToken:
        return @"Revoke Access Token";
    case TableAction_VerifyAccessToken:
        return @"Verify Access Token";
    default:
        return @"Unknown";
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];

    [LineSDKWrapper
        registerOnSuccess:^(NSString *message) {
          NSLog(@"[LineSDK][Bridge][OnSuccess]\n%@", message);
        }
        onFailure:^(NSString *message) {
          NSLog(@"[LineSDK][Bridge][OnFailure]\n%@", message);
        }];
}

- (NSInteger)tableView:(nonnull UITableView *)tableView
    numberOfRowsInSection:(NSInteger)section {
    return TableAction_Count;
}

- (nonnull UITableViewCell *)tableView:(nonnull UITableView *)tableView
                 cellForRowAtIndexPath:(nonnull NSIndexPath *)indexPath {

    UITableViewCell *cell =
        [tableView dequeueReusableCellWithIdentifier:@"cell"];
    TableAction action = (TableAction)indexPath.row;
    [cell textLabel].text = [self labelForAction:action];
    return cell;
}

- (void)tableView:(UITableView *)tableView
    didSelectRowAtIndexPath:(NSIndexPath *)indexPath {

    [tableView deselectRowAtIndexPath:indexPath animated:YES];

    NSString *currentAccessToken = @"";

    TableAction action = (TableAction)indexPath.row;
    switch (action) {
    case TableAction_SetupSDK:
        [[LineSDKWrapper sharedInstance] setupChannelID:@"1620019587"
                                          universalLink:@""];
        break;
    case TableAction_Login:
        [[LineSDKWrapper sharedInstance]
            loginWithIdentifier:[self generateIdentifier]
                         scopes:@"profile"
                   onlyWebLogin:NO
                      botPrompt:nil
                   IDTokenNonce:nil];
        break;
    case TableAction_GetProfile:
        [[LineSDKWrapper sharedInstance]
            getProfileWithIdentifier:[self generateIdentifier]];
        break;
    case TableAction_GetCurrentAccessToken:
        currentAccessToken =
            [[LineSDKWrapper sharedInstance] currentAccessToken];
        NSLog(@"[LineSDK][Current Access Token]\n%@", currentAccessToken);
        break;
    case TableAction_Logout:
        [[LineSDKWrapper sharedInstance]
            logoutWithIdentifier:[self generateIdentifier]];
        break;
    case TableAction_GetBotFriendshipStatus:
        [[LineSDKWrapper sharedInstance]
            getBotFriendshipStatusWithIdentifier:[self generateIdentifier]];
        break;
    case TableAction_RefreshAccessToken:
        [[LineSDKWrapper sharedInstance]
            refreshAccessTokenWithIdentifier:[self generateIdentifier]];
        break;
    case TableAction_RevokeAccessToken:
        [[LineSDKWrapper sharedInstance]
            revokeAccessTokenWithIdentifier:[self generateIdentifier]];
        break;
    case TableAction_VerifyAccessToken:
        [[LineSDKWrapper sharedInstance]
            verifyAccessTokenWithIdentifier:[self generateIdentifier]];
        break;
    default:
        break;
    }
}

- (NSString *)generateIdentifier {
    NSUUID *uuid = [NSUUID UUID];
    NSString *uuidString = [uuid UUIDString];
    return [uuidString lowercaseString];
}

@end
