//
//  Socket.h
//  SocketIO
//
//  Created by Patrick Perini on 6/13/14.
//
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

#ifdef __IPHONE_8_0
#import <WebKit/WebKit.h>
#endif


@interface SIOSocket : NSObject

// Generators
+ (void)socketWithHost:(NSString *)hostURL response:(void(^)(SIOSocket *socket))response;
+ (void)socketWithHost:(NSString *)hostURL reconnectAutomatically:(BOOL)reconnectAutomatically attemptLimit:(NSInteger)attempts withDelay:(NSTimeInterval)reconnectionDelay maximumDelay:(NSTimeInterval)maximumDelay timeout:(NSTimeInterval)timeout response:(void(^)(SIOSocket *socket))response;


@property (readonly) JSContext *javascriptContext;

// Event responders
@property (nonatomic, copy) void (^onConnect)();
@property (nonatomic, copy) void (^onDisconnect)();
@property (nonatomic, copy) void (^onError)(NSDictionary *errorInfo);

@property (nonatomic, copy) void (^onReconnect)(NSInteger numberOfAttempts);
@property (nonatomic, copy) void (^onReconnectionAttempt)(NSInteger numberOfAttempts);
@property (nonatomic, copy) void (^onReconnectionError)(NSDictionary *errorInfo);


- (void)on:(NSString *)event callback:(void (^)(id, id))function;

// Emitters
- (void)emit:(NSArray *)events;
- (void)emit:(NSString *)event payload:(id)payload callback:(void (^)(id, id))function;

- (void)close;

@end
