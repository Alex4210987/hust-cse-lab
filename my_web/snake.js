// 定义常量
const gameBoard = document.getElementById('game-board');
const snake = document.getElementById('snake');
const food = document.getElementById('food');

// 定义变量
let snakeX = 0;
let snakeY = 0;
let foodX = 0;
let foodY = 0;
let score = 0;
let direction = 'right';
let intervalId;

// 初始化游戏
function initGame() {
    // 初始化蛇的位置
    snake.style.top = '0px';
    snake.style.left = '0px';
    snakeX = 0;
    snakeY = 0;

    // 初始化食物的位置
    foodX = Math.floor(Math.random() * (gameBoard.offsetWidth / 20)) * 20;
    foodY = Math.floor(Math.random() * (gameBoard.offsetHeight / 20)) * 20;
    food.style.top = foodY + 'px';
    food.style.left = foodX + 'px';

    // 初始化分数
    score = 0;
    document.getElementById('score').innerText = score;

    // 开始游戏循环
    startGameLoop();
}

// 开始游戏循环
function startGameLoop() {
    clearInterval(intervalId);
    intervalId = setInterval(() => {
        moveSnake();
        checkCollisions();
    }, 150);
}

// 移动蛇的位置
function moveSnake() {
    if (direction === 'right') {
        snakeX += 20;
    } else if (direction === 'left') {
        snakeX -= 20;
    } else if (direction === 'up') {
        snakeY -= 20;
    } else if (direction === 'down') {
        snakeY += 20;
    }
    snake.style.top = snakeY + 'px';
    snake.style.left = snakeX + 'px';
}

// 检查碰撞
function checkCollisions() {
    // 检查是否撞到边界
    if (snakeX < 0 || snakeX > gameBoard.offsetWidth - snake.offsetWidth ||
        snakeY < 0 || snakeY > gameBoard.offsetHeight - snake.offsetHeight) {
        gameOver();
    }

    // 检查是否吃到食物
    if (snakeX === foodX && snakeY === foodY) {
        score++;
        document.getElementById('score').innerText = score;
        foodX = Math.floor(Math.random() * (gameBoard.offsetWidth / 20)) * 20;
        foodY = Math.floor(Math.random() * (gameBoard.offsetHeight / 20)) * 20;
        food.style.top = foodY + 'px';
        food.style.left = foodX + 'px';
    }
}

// 游戏结束
function gameOver() {
    clearInterval(intervalId);
    alert('游戏结束，得分：' + score);
}

// 监听按键事件
//bindKey() {
document.addEventListener('keydown', event => {
    if (event.code === 'ArrowRight' && direction !== 'left') {
        direction = 'right';
    } else if (event.code === 'ArrowLeft' && direction !== 'right') {
        direction = 'left';
    } else if (event.code === 'ArrowUp' && direction !== 'down') {
        direction = 'up';
    } else if (event.code === 'ArrowDown' && direction !== 'up') {
        direction = 'down';
    }
});


// 初始化游戏
initGame();