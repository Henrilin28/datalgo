#include <iostream>
#include <vector>
#include <queue>

class Image {
public:
    Image(const std::vector<std::vector<unsigned int>>& img):_img(img) {
    }
    
    void print_img() {
        for (int i = 0; i < _img.size(); i++) {
            for (int j = 0; j < _img.size(); j++) {
                std::cout << _img[j][i] << " ";
            }
            std::cout << "\n";
        }
    }
    
    unsigned int get_color(std::size_t line, std::size_t col) {
        return _img[col][line];
    }
    
    void set_color(std::size_t line, std::size_t col, unsigned int color) {
        _img[col][line] = color;
    }
    
    bool is_valid(std::size_t line, std::size_t col) {
        return (line < _img[0].size() && col < _img.size() && col >= 0 && line >= 0);
    }
    
    void color_zone(std::size_t line, std::size_t col, unsigned int color) {
        _color_zone(line, col, get_color(line, col), color);
    }
    
    //recursive
    void _color_zone(std::size_t line, std::size_t col, unsigned int color, unsigned int target) {
    
        if (is_valid(line, col) && get_color(line, col) == color) {
            set_color(line, col, target);
            _color_zone(line + 1, col, color, target);
            _color_zone(line - 1, col, color, target);
            _color_zone(line, col + 1, color, target);
            _color_zone(line, col - 1, color, target);
            
            /*
            _color_zone(line + 1, col + 1, color, target);
            _color_zone(line - 1, col + 1, color, target);
            _color_zone(line + 1, col - 1, color, target);
            _color_zone(line - 1, col - 1, color, target);
            */
        }
    }
    
    //BFS based solution
    void color_zone2(std::size_t line, std::size_t col, unsigned int color) {
        
        std::queue<std::pair<std::size_t, std::size_t>> work;
        unsigned int orig_color = get_color(line, col);
        work.push({line, col});
        while(!work.empty()) {
        
            auto p = work.front();
            set_color(p.first, p.second, color);
            if (is_valid(p.first + 1, p.second) && get_color(p.first + 1, p.second) == orig_color)
                work.push({p.first + 1, p.second});
                
            if (is_valid(p.first - 1, p.second) && get_color(p.first - 1, p.second) == orig_color)
                work.push({p.first - 1, p.second});
                
            if (is_valid(p.first, p.second + 1) && get_color(p.first, p.second + 1) == orig_color)
                work.push({p.first, p.second + 1});
                
            if (is_valid(p.first, p.second - 1) && get_color(p.first, p.second - 1) == orig_color)
                work.push({p.first, p.second - 1});
                
            work.pop();
        }
        
    }

private:    
    std::vector<std::vector<unsigned int>> _img;
    
};


void test_img() {
    std::vector<std::vector<unsigned int>> a = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, 
        {0, 1, 1, 0, 1, 1}, {1, 0, 0, 0, 2, 2}, {1, 0, 0, 0, 1, 2}, {0, 1, 0, 1, 1, 2}} ;
        
    Image img(a);
    img.print_img();
    std::cout << img.get_color(1, 5) << "\n";
    std::cout << std::boolalpha << img.is_valid(0, 0) << "\n";
    img.color_zone2(3, 3, 4);
    img.print_img();
}
