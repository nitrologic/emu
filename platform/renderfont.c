// #include <rendfont.h>


typedef char unicode_char;
typedef int INT32;
typedef struct render_font render_font;
typedef struct render_texture render_texture;
typedef int render_bounds;
typedef int rectangle;
typedef void bitmap_t;

render_font *render_font_alloc(const char *filename){
	return 0;
}

void render_font_free(render_font *font){
	
}

INT32 render_font_get_pixel_height(render_font *font){
	return 0;
}

render_texture *render_font_get_char_texture_and_bounds(render_font *font, float height, float aspect, unicode_char ch, render_bounds *bounds)
{
	return 0;
}

void render_font_get_scaled_bitmap_and_bounds(render_font *font, bitmap_t *dest, float height, float aspect, unicode_char chnum, rectangle *bounds){
}

float render_font_get_char_width(render_font *font, float height, float aspect, unicode_char ch){
	return 0.0;
}

float render_font_get_string_width(render_font *font, float height, float aspect, const char *string){
	return 0.0;
}

float render_font_get_utf8string_width(render_font *font, float height, float aspect, const char *utf8string){
	return 0.0;
}
