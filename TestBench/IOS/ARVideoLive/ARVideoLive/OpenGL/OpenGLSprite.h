/**
 *  @file OpenGLSprite.h
 *
 * Copyright 2009 Parrot SA. All rights reserved.
 * @author D HAEYER Frederic
 * @date 2009/10/26
 */

#if USE_OPENGL

#include "opengl_texture.h"

@protocol OpenGLSpriteDelegate<NSObject>

- (void)updateScaleMatrix;

@end


@interface OpenGLSprite : NSObject {
	ARDroneSize	 screen_size;
	ARDroneSize    old_size;

@protected
    BOOL screenOrientationRight;
    BOOL screenOrientationChanged;
	void            *default_image;
	ARDroneScaling	 scaling;
	ARDroneOpenGLTexture *texture;
    GLuint           program;
    id <OpenGLSpriteDelegate> delegate;
}

@property (nonatomic, assign) BOOL screenOrientationRight;

- (id)initWithFrame:(CGRect)frame withScaling:(ARDroneScaling)_scaling withProgram:(GLuint)programId withData:(ARDroneOpenGLTexture *)data withDelegate:(id <OpenGLSpriteDelegate>)_delegate;
- (void)drawSelf;
- (void)setScaling:(ARDroneScaling)newScaling;
- (ARDroneScaling)getScaling;
- (ARDroneOpenGLTexture *)getTexture;

- (int)getAndResetNbDisplayed;

@end

#endif //USE_OPENGL