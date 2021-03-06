#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "p2Point.h"

class Gui;
class GuiImage;
class GuiLabel; 
class GuiInputText;
class GuiLoadBar;
class GuiHSlider;
class GuiVSlider;
class GuiMCursor;
class GuiRect;

struct SDL_Texture;
struct SDL_Color;

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// Gui creation functions
	GuiImage* CreateImage(const char* filename);
	GuiImage* CreateImage(const rectangle& atlas_section);
	GuiLabel* CreateLabel(const char* text);
	GuiInputText* CreateInput(const rectangle& section, const char* default_text, uint width, const iPoint& offset = { 0, 0 }, bool password = false, int max_quantity = 0);
	GuiLoadBar* CreateBar(float value, const rectangle& bar_sect, const rectangle& cover_sect, bool show_text = false);
	GuiHSlider* CreateHSlider(const rectangle& bar, const rectangle& thumb, const rectangle& bar_offset, const iPoint& thumb_margins, float value);
	GuiVSlider* CreateVSlider(const rectangle& bar, const rectangle& thumb, const rectangle& bar_offset, const iPoint& thumb_margins, float value);
	GuiMCursor* CreateGuiMCursor(const char* filename, int margin_x, int margin_y);
	GuiMCursor* CreateGuiMCursor(const char* filename, const rectangle& section, int margin_x, int margin_y);
	GuiRect* CreateGuiRect(const rectangle& _rect, SDL_Color _color);
	
	bool DeleteGuiElement(Gui* elem);
	void DisableGuiElement(Gui* elem);
	void EnableGuiElement(Gui* elem);

	const Gui* FindMouseHover() const;
	const SDL_Texture* GetAtlas() const;

	bool Save(pugi::xml_node&)const;
	bool Load(pugi::xml_node&);

	bool Focus(Gui* gui);

private:

	bool debug = false;
	p2List<Gui*> elements;
	const Gui* focus = nullptr;
	SDL_Texture* atlas = nullptr;
	p2SString atlas_file_name;

};

#endif // __j1GUI_H__