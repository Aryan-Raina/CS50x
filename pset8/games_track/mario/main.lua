--[[
    Super Mario Bros. Demo
    Author: Colton Ogden
    Original Credit: Nintendo

    Demonstrates rendering a screen of tiles.
]]

Class = require 'class'
push = require 'push'

require 'Animation'
require 'Map'
require 'Player'

-- close resolution to NES but 16:9
VIRTUAL_WIDTH = 432
VIRTUAL_HEIGHT = 243

-- actual window resolution
WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720

-- seed RNG
math.randomseed(os.time())

-- an object to contain our map data
map = Map()

-- makes upscaling look pixel-y instead of blurry
love.graphics.setDefaultFilter('nearest', 'nearest')

-- performs initialization of all objects and data needed by program
function love.load()

    -- sets up a different, better-looking retro font as our default
    love.graphics.setFont(love.graphics.newFont('fonts/font.ttf', 8))

    -- game is at which state
    gameState = 'start'

    -- which level
    level = 1

    -- sets up virtual screen resolution for an authentic retro feel
    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, {
        fullscreen = false,
        resizable = true
    })

    love.window.setTitle('Super Mario 50')

    love.keyboard.keysPressed = {}
    love.keyboard.keysReleased = {}
end

-- called whenever window is resized
function love.resize(w, h)
    push:resize(w, h)
end

-- global key pressed function
function love.keyboard.wasPressed(key)
    if (love.keyboard.keysPressed[key]) then
        return true
    else
        return false
    end
end

-- global key released function
function love.keyboard.wasReleased(key)
    if (love.keyboard.keysReleased[key]) then
        return true
    else
        return false
    end
end

-- called whenever a key is pressed
function love.keypressed(key)
    if key == 'escape' then
        love.event.quit()
    end
    if key == 'space' then
        if gameState == 'start' then
            gameState = 'play'
        end

        if gameState == 'flag' then 
            gameState = 'next_level'
            level = level + 1
        end

    end

    love.keyboard.keysPressed[key] = true
end

-- called whenever a key is released
function love.keyreleased(key)
    love.keyboard.keysReleased[key] = true
end

-- called every frame, with dt passed in as delta in time since last frame
function love.update(dt)
    if gameState == 'next_level' then
        -- an object to contain our map data
        map = Map()
        gameState = 'play'
    end
    if gameState == 'play' then
        map:update(dt)
    end

    -- reset all keys pressed and released this frame
    love.keyboard.keysPressed = {}
    love.keyboard.keysReleased = {}
end

-- called each frame, used to render to the screen
function love.draw()
    -- begin virtual resolution drawing
    push:apply('start')
    
    if gameState == 'start' then
        love.graphics.setFont(love.graphics.newFont('fonts/font.ttf', 20))
        love.graphics.clear(100/255, 0/255, 100/255, 255/255)
        love.graphics.printf("Press space To Play!", 0, VIRTUAL_HEIGHT / 2, VIRTUAL_WIDTH, 'center')

    elseif gameState == 'flag' then
        love.graphics.setFont(love.graphics.newFont('fonts/font.ttf', 20))
        love.graphics.clear(100/255, 0/255, 100/255, 255/255)
        love.graphics.printf("Press space To Start Next Level", 0, VIRTUAL_HEIGHT / 2, VIRTUAL_WIDTH, 'center')
    elseif gameState == 'play' then
        love.graphics.setFont(love.graphics.newFont('fonts/font.ttf', 8))
        -- clear screen using Mario background blue
        love.graphics.clear(108/255, 140/255, 255/255, 255/255)

        -- renders our map object onto the screen
        love.graphics.translate(math.floor(-map.camX + 0.5), math.floor(-map.camY + 0.5))
        map:render()

        love.graphics.printf("Level " .. tostring(level), 0, 10, 30, 'center')
    elseif gameState == 'lost'then
        love.graphics.setFont(love.graphics.newFont('fonts/font.ttf', 50))
        love.graphics.clear(100/255, 0/255, 100/255, 255/255)
        love.graphics.printf("YOU LOSE!!!!!", 0, VIRTUAL_HEIGHT / 2, VIRTUAL_WIDTH, 'center')
    end

    -- end virtual resolution
    push:apply('end')
end