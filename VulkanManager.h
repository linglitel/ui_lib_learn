/*
//
// Created by linglitel on 24-9-3.
//

#ifndef VULKANMANAGER_H
#define VULKANMANAGER_H



#include <vulkan/vulkan.h>

class VulkanManager {
public:
    static VulkanManager& getInstance() {
        static VulkanManager instance; // Guaranteed to be destroyed.
        return instance; // Instantiated on first use.
    }

    // Delete copy constructor and assignment operator
    VulkanManager(VulkanManager const&) = delete;
    void operator=(VulkanManager const&) = delete;

    bool initialize();
    void cleanup();

    VkInstance getInstanceHandle() const { return instance; }
    VkDevice getDeviceHandle() const { return device; }
    VkQueue getQueueHandle() const { return queue; }

private:
    VulkanManager() {} // Constructor is private

    VkInstance instance = VK_NULL_HANDLE;
    VkDevice device = VK_NULL_HANDLE;
    VkQueue queue = VK_NULL_HANDLE;

    bool createInstance();
    bool createDevice();
    bool createQueue();
};

bool VulkanManager::initialize() {
    return createInstance() && createDevice() && createQueue();
}

void VulkanManager::cleanup() {
    if (device != VK_NULL_HANDLE) {
        vkDestroyDevice(device, nullptr);
    }
    if (instance != VK_NULL_HANDLE) {
        vkDestroyInstance(instance, nullptr);
    }
}

bool VulkanManager::createInstance() {
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan App";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    return vkCreateInstance(&createInfo, nullptr, &instance) == VK_SUCCESS;
}

bool VulkanManager::createDevice() {
    // Device creation code here
    return true;
}

bool VulkanManager::createQueue() {
    // Queue creation code here
    return true;
}




#endif //VULKANMANAGER_H
*/
