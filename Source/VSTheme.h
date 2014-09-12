//
//  VSTheme.h
//  Q Branch LLC
//
//  Created by Brent Simmons on 6/26/13.
//  Copyright (c) 2012 Q Branch LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, VSTextCaseTransform) {
    VSTextCaseTransformNone,
    VSTextCaseTransformUpper,
    VSTextCaseTransformLower
};

#define VSTHEME_BOOL(theme, name)   \
    BOOL name = [theme boolForKey:@#name]

#define VSTHEME_NSSTRING(theme, name)   \
    NSString* name = [theme stringForKey:@#name]

#define VSTHEME_NSINTEGER(theme, name)  \
    NSUInteger name = [theme integerForKey:@#name]

#define VSTHEME_CGFLOAT(theme, name)  \
    CGFloat name = [theme floatForKey:@#name]

#define VSTHEME_UIIMAGE(theme, name)  \
    UIImage *name = [theme imageForKey:@#name]

#define VSTHEME_UICOLOR(theme, name)  \
    UIColor *name = [theme colorForKey:@#name]

#define VSTHEME_UIEDGEINSETS(theme, name)   \
    UIEdgeInsets name = [theme edgeInsetsForKey:@#name]

#define VSTHEME_CGRECT(theme, name) \
    CGRect name = [theme rectForKey:@#name]

#define VSTHEME_UIFONT(theme, name)   \
    UIFont *name = [theme fontForKey:@#name]

#define VSTHEME_CGPOINT(theme, name) \
    CGPoint name = [theme pointForKey:@#name]

#define VSTHEME_CGSIZE(theme, name) \
    CGSize name = [theme sizeForKey:@#name]

#define VSTHEME_NSTIMEINTERVALE(theme, name) \
    NSTimeInterval name = [theme timeIntervalForKey:@#name]

#define VSTHEME_UIVIEWANIMATIONOPTIONS(theme, name) \
    UIViewAnimationOptions name = [theme curveForKey:@#name]

#define VSTHEME_VSANIMATIONSPECIFIER(theme, name) \
    VSAnimationSpecifier *name = [theme animationSpecifierForKey:@#name]

#define VSTHEME_VSTEXTCASETRANSFORM(theme, name) \
    VSTextCaseTransform *name = [theme textCaseTransformForKey:@#name]

@class VSAnimationSpecifier;

@interface VSTheme : NSObject

- (id)initWithDictionary:(NSDictionary *)themeDictionary;

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) VSTheme *parentTheme; /*can inherit*/

- (BOOL)boolForKey:(NSString *)key;
- (NSString *)stringForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
- (CGFloat)floatForKey:(NSString *)key;
- (UIImage *)imageForKey:(NSString *)key; /*Via UIImage imageNamed:*/
- (UIColor *)colorForKey:(NSString *)key; /*123ABC or #123ABC: 6 digits, leading # allowed but not required*/
- (UIEdgeInsets)edgeInsetsForKey:(NSString *)key; /*xTop, xLeft, xRight, xBottom keys*/
- (CGRect)rectForKey:(NSString *)key; /*xX, xY, xWidth, xHeight keys*/
- (UIFont *)fontForKey:(NSString *)key; /*x and xSize keys*/
- (CGPoint)pointForKey:(NSString *)key; /*xX and xY keys*/
- (CGSize)sizeForKey:(NSString *)key; /*xWidth and xHeight keys*/
- (NSTimeInterval)timeIntervalForKey:(NSString *)key;

- (UIViewAnimationOptions)curveForKey:(NSString *)key; /*Possible values: easeinout, easeout, easein, linear*/
- (VSAnimationSpecifier *)animationSpecifierForKey:(NSString *)key; /*xDuration, xDelay, xCurve*/

- (VSTextCaseTransform)textCaseTransformForKey:(NSString *)key; /*lowercase or uppercase -- returns VSTextCaseTransformNone*/

@end


@interface VSTheme (Animations)

- (void)animateWithAnimationSpecifierKey:(NSString *)animationSpecifierKey animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion;

@end


@interface VSAnimationSpecifier : NSObject

@property (nonatomic, assign) NSTimeInterval delay;
@property (nonatomic, assign) NSTimeInterval duration;
@property (nonatomic, assign) UIViewAnimationOptions curve;

@end

